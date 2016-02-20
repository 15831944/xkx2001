// logind.c
// added mirror stuff, 12/19/98

#include <ansi.h>
#include <command.h>
#include <login.h>

#define SUICIDE_LIST "/log/static/SUICIDE.c"
#define MAX_USERS 230

inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name = ({
	"��", "��", "��", "��", "��", "��", "��",
	"ΤС��", "ĳ��", "��", "ҥ��", "������",
	"��ӹ", 
});

private void get_id(string arg, object ob);
private void confirm_id(string yn, object ob);
object make_body(object ob);
private void init_new_player(object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_login(object me);
object find_body(string name);
int check_legal_id(string arg,object ob);
string check_legal_name(string arg,object ob);


private void write_ob(object ob,string msg)
{
	if( objectp(ob) && ob->query("language") == "BIG5")
		msg = "/adm/daemons/languaged"->toBig5(msg);

	write(msg);
}


private void random_gift(mapping my)
{
	int i;
	int tmpstr, tmpint, tmpcon, tmpdex,tmpend;
	tmpstr = tmpint = tmpcon = tmpdex = tmpend = 10;

	for (i = 0; i < 50; i++) {
		switch (random(5)) {
		case 0: tmpstr++; break;
		case 1: tmpint++; break;
		case 2: tmpcon++; break;
		case 3: tmpdex++; break;
		case 4: tmpend++; break;
		}
	}
	if (tmpstr <= 30) my["str"] = tmpstr; else my["str"] = 30;
	if (tmpint <= 30) my["int"] = tmpint; else my["int"] = 30;
	if (tmpcon <= 30) my["con"] = tmpcon; else my["con"] = 30;
	if (tmpdex <= 30) my["dex"] = tmpdex; else my["dex"] = 30;

	my["end"] = 100 - my["dex"] - my["str"] - my["int"] - my["con"];

	// next 2 are randomly selected
	my["kar"] = 10 + random(21);
	my["pat"] = 10 + random(21);
	my["per"] = 60 - my["kar"] - my["pat"];
}

void create()
{
	seteuid(getuid());
	set("channel_id", "���߾���");
}

private void confirm_big5(string arg, object ob)
{
	object *usr;
	int i, wiz_cnt, ppl_cnt, login_cnt;
	object ppl;
	string msg;


	arg = lower_case(arg);

	if( arg == "y" || arg == "yes")
	{
		ob->set("language","BIG5");
		write_ob(ob,"Ok, use BIG5 code.\n\n");
	}
	else
	{
		ob->set("language","GB");
		write_ob(ob,"Ok, use GB code.\n\n");
	}

	usr = users();
	wiz_cnt = 0;
	ppl_cnt = 0;
	login_cnt = 0;
	for(i=0; i<sizeof(usr); i++) {
		if( !environment(usr[i]) ) login_cnt++;
		else if( wizardp(usr[i]) ) wiz_cnt++;
		else ppl_cnt++;
	}


	msg = "Ŀǰ��վ����" + (string)chinese_number(wiz_cnt) + "λ��ʦ��" + (string)chinese_number(ppl_cnt);
	msg += "λ��������ϣ��Լ�" + (string)chinese_number(login_cnt) + "λʹ���߳��������С�\n";
	msg += "����Ӣ�����֣�����ҿ�ѡһϲ�������֣���";

	write_ob(ob,msg);

	input_to( (: get_id :), ob );
}

void logon(object ob)
{
	object *usr;
	int i, wiz_cnt, ppl_cnt, login_cnt;

	if (BAN_D->is_banned(query_ip_name(ob)) == 1) {
		write_ob(ob,"��ĵ�ַ�ڱ� MUD ���ܻ�ӭ��Your IP not welcome in this MUD.\n");
		destruct(ob);
		return;
	}

#ifdef MAX_USERS
	if( sizeof(users()) >= MAX_USERS - 4 ) {
			write_ob(ob,"�Բ���" + MUD_NAME + "��ʹ�����Ѿ�̫���ˣ������������\n");
			destruct(ob);
			return;
	}
#endif


	cat(WELCOME);
	MUDLIST_CMD->main(this_object(), "");
	//UPTIME_CMD->main();

	write_ob(ob,"\nDo you want to use BIG5 code?(y/n)\n");
	input_to("confirm_big5", ob);
}

private void get_id(string arg, object ob)
{
	object ppl;
	string language;

	arg = lower_case(arg);
	if( !check_legal_id(arg,ob)) {
		write_ob(ob,"����Ӣ�����֣�");
		input_to("get_id", ob);
		return;
	}

#ifdef MAX_USERS
	if( (string)SECURITY_D->get_status(arg)=="(player)"
	&& sizeof(users()) >= MAX_USERS - 4) {
		ppl = find_body(arg);
		// Only allow reconnect an interactive player when MAX_USERS exceeded.
		if( !ppl || !interactive(ppl) ) {
			write_ob(ob,"�Բ���" + MUD_NAME + "��ʹ�����Ѿ�̫���ˣ������������\n");
			destruct(ob);
			return;
		}
	}
#endif


	if( wiz_level(arg) && !SECURITY_D->valid_wiz_login(arg, query_ip_number(ob)) ) {
		write_ob(ob,"�Բ�����ӵǼǵĵ�ַʹ����ʦ�ʺš�\n");
		log_file("WIZ_LOGIN", sprintf("%s: Attempting login %s from %s\n", ctime(time()), arg, query_ip_name(ob)));
		destruct(ob);
		return;
	}


	/*write_ob(ob,"\n���������ڵĵ�ַ�ǣ�202.96.91.22 5555\n\n\n");
	if (wiz_level(arg) == 0) {
		destruct(ob);
		return;
	}*/

	if( wiz_level(arg) < wiz_lock_level ) {
		write_ob(ob,"�Բ���" + MUD_NAME + "Ŀǰ������ʦ�ȼ� " + WIZ_LOCK_LEVEL
			+ " ���ϵ��˲������ߡ�\n");
		destruct(ob);
		return;
	}

	if( (string)ob->set("id", arg) != arg ) {
		write_ob(ob,"Failed setting user name.\n");
		destruct(ob);
		return;
	}

//	if( arg=="guest" ) {
//		// If guest, let them create the character.
//		confirm_id("Yes", ob);
//		return;
//	} else

	if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
		language = ob->query("language");
		if( ob->restore() ) {
			ob->set("language",language);
			write_ob(ob,"���������룺");
			input_to("get_passwd", 1, ob);
			return;
		}
		write_ob(ob,"�������ﴢ�浲����һЩ���⣬������ guest ����֪ͨ��ʦ����\n");
		destruct(ob);
		return;
	} else { // check if someone is already trying to create this id
		if( find_login(ob) ) {
			write_ob(ob,"����Ҳ�ڴ�����������ѡ������Ӣ�����֡�\n");
			write_ob(ob,"����Ӣ�����֣�");
			input_to("get_id", ob);
			return;
		}
	}

// dts: check reg-ban setting
	if (REGBAN_D->is_banned(query_ip_name(ob)) == 1) {
		write_ob(ob,"�� MUD ����ӭ�㴴���µ����");
		destruct(ob);
		return;
	}

	write_ob(ob,"ʹ�� " + (string)ob->query("id") + " ������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
	input_to("confirm_id", ob);
}

private void get_passwd(string pass, object ob)
{
	string my_pass, file, *tmp;
	object user;
	int cnt;

	write_ob(ob,"\n");
	my_pass = ob->query("password");
	if( crypt(pass, my_pass) != my_pass ) {
		write_ob(ob,"�������\n");
		if( wiz_level(ob->query("id")) )
			log_file("WIZ_LOGIN", sprintf("%s: Failed login %s from %s\n",
				ctime(time()), ob->query("id"), query_ip_name(ob)));
		destruct(ob);
		return;
	}

	// Check if this player has already suicided before.
	file = read_file(SUICIDE_LIST);
	if ( sizeof(file) > 0 ) {
	   tmp = explode(file, "\n");
		
	   for( cnt=0; cnt < sizeof(tmp); cnt++ ) {
                if( tmp[cnt][0] == '#' || tmp[cnt][0] == '\n' || tmp[cnt] == "" )
                        continue;
                else if ( strsrch( tmp[cnt], "*"+ob->query("id")+" commits" ) >= 0 ) {
			write_ob(ob,"���Ѿ���ɱ�ˣ���ô�ܹ������أ�\n");
			destruct(ob);
	                return;
        	}
	    }
	}

	// Check if we are already playing.
	user = find_body(ob->query("id"));
	if (user) {
		 user->set("language",ob->query("language"));
		if( user->query_temp("netdead") ) {
			reconnect(ob, user);
			return;
		}
		write_ob(ob,"��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}

	if( objectp(user = make_body(ob)) ) {
		if( user->restore() ) {
		   user->set("language",ob->query("language"));
			log_file( "USAGE", sprintf("%s(%s) loggined from %s (%s)\n", user->query("name"), user->query("id"),
				query_ip_name(ob), ctime(time()) ) );
			enter_world(ob, user);
			return;
		} else {
			destruct(user);
		}
	}
	write_ob(ob,"�������´���������\n");
	confirm_id("y", ob);
}

private void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if( yn=="" ) {
		write_ob(ob,"��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write_ob(ob,"�ðɣ���ӭ�´�������\n");
		destruct(ob);
		return;
	} else {
		tell_object(user, "���˴ӱ�( " + query_ip_number(ob)
			+ " )����ȡ���������Ƶ����\n");
		log_file( "USAGE", sprintf("%s(%s) replaced by %s (%s)\n", user->query("name"), user->query("id"),
			query_ip_name(ob), ctime(time()) ) );
	}

	// Kick out tho old player.
	old_link = user->query_temp("link_ob");
	if( old_link ) {
		exec(old_link, user);
		destruct(old_link);
	}

	reconnect(ob, user);
}

private void confirm_id(string yn, object ob)
{
	if( yn=="" ) {
		write_ob(ob,"ʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
		input_to("confirm_id", ob);
		return;
	}

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write_ob(ob,"�ðɣ���ô��������������Ӣ�����֣�");
		input_to("get_id", ob);
		return;
	}
	write_ob(ob, @TEXT

���������ĸ��մ���������������ִ��������������Ժ��ܸ��ģ�
����������������Ź۵�������������Ϸ�ܾ���½����

TEXT
	);
	write_ob(ob,"�����������֣�");
	input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{
	if( !(arg = check_legal_name(arg,ob) )) {
		write_ob(ob,"�����������֣�");
		input_to("get_name", ob);
		return;
	}
	//write_ob(ob,"%O\n", ob);
	if( objectp(ob) && ob->query("language") == "BIG5")
		arg = "/adm/daemons/languaged"->toGB(arg);
	ob->set("name", arg);

	write_ob(ob,"���趨�������룺");
	input_to("new_password", 1, ob);
}

private void new_password(string pass, object ob)
{
	write_ob(ob,"\n");
	if( strlen(pass)<5 ) {
		write_ob(ob,"����ĳ�������Ҫ�����Ԫ���������������룺");
		input_to("new_password", 1, ob);
		return;
	}
	ob->set("password", crypt(pass,0) );
	write_ob(ob,"��������һ���������룬��ȷ����û�Ǵ�");
	input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
	mapping my;
	string old_pass;
	write_ob(ob,"\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write_ob(ob,"��������������벢��һ�����������趨һ�����룺");
		input_to("new_password", 1, ob);
		return;
	}

	write_ob(ob,@TEXT

һ��������츳��������������ϰ������ϢϢ��ء��������е����������
���������츳��

	������Ӱ�칥���������������Ĵ�С��
	���ԣ�Ӱ��ѧϰ�书�ؼ����ٶȼ����ʦ����������
	���ǣ�Ӱ�������ָ����ٶȼ������������ӵ�������
	����Ӱ���������ܵ�������
	������Ӱ����ս�͹������;�����

TEXT);
	my = ([]);
	random_gift(my);
	write_ob(ob,sprintf("\n����[%d]�� ����[%d]�� ����[%d]�� ��[%d]�� ����[%d]\n",
					 my["str"], my["int"], my["con"], my["dex"], my["end"]) );

  write_ob(ob,"��������һ���츳��");
  input_to("get_gift", ob, my);
}

private void get_gift(string yn, object ob, mapping my)
{
	if (yn[0] != 'y' && yn[0] != 'Y') {
		random_gift(my);
		write_ob(ob,sprintf("\n����[%d]�� ����[%d]�� ����[%d]�� ��[%d]�� ����[%d]\n",
					 my["str"], my["int"], my["con"], my["dex"], my["end"]) );

		write_ob(ob,"��ͬ����һ���츳��");
		input_to("get_gift", ob, my);
	}
	if (yn[0] == 'y' || yn[0] == 'Y') {
				write_ob(ob,"\n���ĵ����ʼ���ַ��");
			input_to("get_email", ob, my);
	}
}

private void get_email(string email, object ob, mapping my)
{
	object user;

	write_ob(ob,"\n");
	if (email == "" || strsrch(email, "@") == -1) {
		write_ob(ob,"�����ʼ���ַ��Ҫ�� id@address �ĸ�ʽ��\n");
		write_ob(ob,"���ĵ����ʼ���ַ��");
		input_to("get_email", ob, my);
		return;
	}
	ob->set("email", email);
	ob->set("registered", "no");

	// If you want do race stuff, ask player to choose one here, then you can
	// set the user's body after the question is answered. The following are
	// options for player's body, so we clone a body here.
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob)) )
		return;
	user->set("str", my["str"]);
	user->set("dex", my["dex"]);
	user->set("con", my["con"]);
	user->set("int", my["int"]);
	ob->set("registered", "no");
	user->set("registered", "no");

	write_ob(ob,"��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
	input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{
	write_ob(ob,"\n");
	if( gender=="" ) {
		write_ob(ob,"��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
		input_to("get_gender", ob, user);
		return;
	}

	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "����");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "Ů��" );
	else {
		write_ob(ob,"�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
		input_to("get_gender", ob, user);
		return;
	}

	log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
		query_ip_name(ob), ctime(time()) ) );
	init_new_player(user);
	enter_world(ob, user);
	write_ob(ob,"\n");
}

object make_body(object ob)
{
	string err;
	object user;
	int n;

	user = new(ob->query("body"));
	if(!user) {
		write_ob(ob,"���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
		write_ob(ob,err+"\n");
		return 0;
	}
	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
	user->set("language", ob->query("language"));
	user->set_name( ob->query("name"), ({ ob->query("id")}) );
	return user;
}

private void init_new_player(object user)
{
	object money;

	user->set("title", "��ͨ����");
	user->set("birthday", time() );
	user->set("potential", 99);
        user->set("max_neili", 400);
        user->set("eff_jingli", 300);
        user->set("max_jingli", 300);

	user->set("channels", ({ "chat", "rumor", "gchat" }) );
	user->create_human_body();

//	money=new("/clone/money/silver");
//	money->set_amount(10);
//	money->move(user);

	// In case of new player, we save them here right aftre setup
//	user->move("/adm/register/reg_room");
//	user->set("startroom", "/adm/register/reg_room");
//	user->save();
	// compeleted.
}


varargs void enter_world(object ob, object user, int silent)
{
	object cloth, room;
	mapping skill_status, my;
	string startroom, family, clas;
	string *sname;
	int select, i, level;
	float exper;

	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	user->set("registered", ob->query("registered"));
	exec(user, ob);

	user->set("language", ob->query("language"));
	write_ob(user,"\nĿǰȨ�ޣ�" + wizhood(user) + "\n");

	user->setup();

	ob->save();

	if( MARRY_D->validate_marriage(user) )
		new("/d/city/obj/pring")->move(user);

	// general user data login check, like combat_exp, balance, clothing.
	UPDATE_D->login_check(user);

	// Menpai specific user data check
	// should have been moved into UPDATE_D if random_gift() were not used.
	if ( user->query("yijin_wan") && user->query("yijin_wan") < user->query("age") - 14 )
	{
		//user->add("max_neili",  -10);
		//user->add("eff_jingli", -10);
		//if (user->query("eff_jingli") < 0) user->set("eff_jingli",0);
		//if (user->query("max_neili") < 0) user->set("max_neili",0);

		my = ([]);
		random_gift(my);
		user->set("str", my["str"] - random(user->query("yijin_wan") - user->query("age") + 14));
		user->set("dex", my["dex"] - random(user->query("yijin_wan") - user->query("age") + 14));
		user->set("con", my["con"] - random(user->query("yijin_wan") - user->query("age") + 14));
		user->set("int", my["int"] - random(user->query("yijin_wan") - user->query("age") + 14));
		//user->set("yijin_wan", user->query("age") - 13);

		tell_object(user, HIR "��һ����δ����̥�׽��裬�������𣡣���\n"NOR);
	}

	user->save();

	if( !silent ) {
		if (ob->query("registered") == 0)
		{
			//cat(UNREG_MOTD);
write("������������������������������������������������������������������������
��      ע�⣡����

		  ����û��ע�ᣬһ���ֵ����ֻ����ע������ʹ�á�

		  ע��Ĳ���ܼ򵥣�����Ҫ���κδ���ʦ�����һ�����
		  �ʼ����ţͣ��ɣ̣������򼸷��ӣ�����һ�죬�����ˡ�
������������������������������������������������������������������������\n");
		}
		else
{
			//cat(MOTD);
			write(
"����������������������������������������������������������������������������
����������������߽��뱾վ�Ժ���������HELP RULES��һ�±�վ�Ĺ��򣬲�Ҫ����
������ǳ���Ҫ��һ�㣬�ⶼ��Ϊ�˱�վ����һ���������õķ�Χ�·�չ��Ҳ�������
������һ�������õĻ�����������������μǣ�������ֲ����֮���档
����������ס��ʱ�浵�����ڵ�����ɵ���Ϸ������ʧ������Ϸ�Ų�����
����������������������������������������������������������������������������\n");

}
		write(sprintf( HIR"�ϴ����ߵ�ַ��\t%s( %s )\n\n"NOR,
			ob->query("last_from"),
			ctime(ob->query("last_on") )
		) );

		write(
HIG"
     *********************************************************************
     *                                                                �� *
     *  ����Ϸ�����ڷ�չ��������������Ϸ��ϣ���õ����ͣգİ����ߵ�֧�� *
     *                                                                �� *
     *********************************************************************

"NOR);


	if( strsrch(ctime(time()), "Dec 24") != -1
		|| strsrch(ctime(time()), "Dec 25") != -1
		|| strsrch(ctime(time()), "Dec 26") != -1
		)
	{
	  cat("/adm/etc/welcome_christmas");
	}

	if( strsrch(ctime(time()), "Jan 1") != -1
		|| strsrch(ctime(time()), "Dec 30") != -1
		|| strsrch(ctime(time()), "Dec 31") != -1
		|| strsrch(ctime(time()), "Jan 2") != -1
		|| strsrch(ctime(time()), "Jan 3") != -1
	)
	{
	  cat("/adm/etc/welcome_newyear");
	}


		if( user->is_ghost() )
			startroom = DEATH_ROOM;
		else if( !stringp(startroom = user->query("startroom"))
			|| !user->query("family") && user->query("combat_exp") < 1)
		startroom = "/d/xiakedao/shatan";
/*			select = random(6);
			if( select == 0 ) startroom = "/d/city/kedian";
			if( select == 1 ) startroom = "/d/quanzhou/wgdamen";
			if( select == 2 ) startroom = "/d/shaolin/nanyang";
			if( select == 3 ) startroom = "/d/xingxiu/beijiang";
			if( select == 4 ) startroom = "/d/qilian/yangguan";
			if( select == 5 ) startroom = "/d/dali/wangfu1";
								if( select == 5 ) startroom = "/d/hangzhou/kedian";
*/
		if ((user->query("registered") != "yes" ||
			REGI_D->is_banned_email(ob->query("email"))) &&
			wizhood(user) == "(player)")
//			user->move("/adm/register/reg_room");
			user->move("/d/xiakedao/shatan1");
		else if( user->query("death_count") > 200 && user->query("combat_exp") < 50000 )
			user->move("/d/death/block.c");
		else if( !catch(load_object(startroom)) )
			user->move(startroom);
		else {
			user->move(START_ROOM);
			startroom = START_ROOM;
			user->set("startroom", START_ROOM);
		}
		tell_room(startroom, user->query("name") + "���߽���������硣\n",
			({user}));
	}
	if (!user->query_temp("cursed"))
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s(%s)��%s���߽��롣", user->name(),user->query("id"), query_ip_name(user)) );
}

varargs void reconnect(object ob, object user, int silent)
{
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	exec(user, ob);

	user->reconnect();
	if( !silent ) {
		tell_room(environment(user), user->query("name") + "�������߻ص�������硣\n",
		({user}));
	}
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s(%s)��%s�������߽��롣", user->query("name"),user->query("id"), query_ip_name(user)) );
}

int check_legal_id(string id,object ob)
{
	int i;

	i = strlen(id);

	if( (strlen(id) < 3) || (strlen(id) > 8 )
	  && (string)SECURITY_D->get_status(id) == "(player)" ) {
		write_ob(ob,"�Բ������Ӣ�����ֱ����� 3 �� 8 ��Ӣ����ĸ��\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' ) {
			write_ob(ob,"�Բ������Ӣ������ֻ����Ӣ����ĸ��\n");
			return 0;
		}

	return 1;
}

string check_legal_name(string name,object ob)
{
	int i,j;

	i = strlen(name);

	if( (strlen(name) < 2) || (strlen(name) > 8 ) || i % 2) {
		write_ob(ob,"�Բ�������������ֱ����� 1 �� 4 �������֡�\n");
		return 0;
	}
	for (j = 0; j < i; j++) {
//		if( name[i]<=' ' ) {
//			write_ob(ob,"�Բ�������������ֲ����ÿ�����Ԫ��\n");
//			return 0;
//		}
		if( j%2==0 && !is_chinese(name[j..j+1]) ) {
			name[j]+=128; name[j+1]+=128;
//			write_ob(ob,"�Բ��������á����ġ�ȡ���֡�\n");
//			return 0;
		}
	}
	if( member_array(name, banned_name)!=-1 ) {
		write_ob(ob,"�Բ����������ֻ���������˵����š�\n");
		return 0;
	}

	return name;
}

object find_login(object me)
{
	object ob, *login;
	string id;
	
	if( !objectp(me) || !stringp(id = me->query("id")) )
		return 0;
	login = children(LOGIN_OB);
	for(int i=0; i<sizeof(login); i++)
		if( clonep(login[i]) && login[i] != me &&
		    login[i]->query("id") == id ) 
			return login[i];

	return 0;
}

object find_body(string name)
{
	object ob, *body;

	if( objectp(ob = find_player(name)) )
		return ob;
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++)
		if( clonep(body[i])
		&&	getuid(body[i]) == name ) return body[i];

	return 0;
}

int set_wizlock(int level)
{
	if( wiz_level(this_player(1)) <= level )
		return 0;
	if( geteuid(previous_object()) != ROOT_UID )
		return 0;
	wiz_lock_level = level;
	return 1;
}
