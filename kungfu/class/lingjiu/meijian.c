// /NPC meijian.c
// By adx @ CuteRabbit 22:21 99-3-19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int auto_perform();

string ask_job();
string ask_escape();
int doing_job(object ob); 
int add_bandit(object ob);
int do_kill(object me, object dest);
int checking(object me);

void create()
{
	set_name("÷��", ({ "mei jian", "mei"}));
	set("long",
	    "���Ǹ���ò毺õ�Ů��, ��������,\n"+
	    "�������, �������.\n"+
	    "���ܾ������ļ�����.\n");
	set("gender", "Ů��");
	set("per", 28);
	set("age", 18);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("per", 32);
	set("class", "scholar");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);

	set("combat_exp", 1000000);
	set("score", 10000);
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("hand",180);
	set_skill("strike", 180);
	set_skill("sword",180);
	set_skill("literate",100);
	set_skill("music",180);

	set_skill("zhemei-shou",180);
	set_skill("liuyang-zhang",180);
	set_skill("tianyu-qijian",180);
	set_skill("yueying-wubu",180);
	set_skill("bahuang-gong", 180);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");

	set("job_count",0);
        set("inquiry", ([
		"job" : (: ask_job :),
		"����" : (: ask_job :),
		"����" : (: ask_job :),
		"����" : (: ask_escape :), 
		"�ɲ���" : (: ask_escape :), //for escape when in job;
		"escape" : (: ask_escape :), 
        ]));

	create_family("���չ�",3,"����");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	setup();
 	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/city/npc/obj/doupeng")->wear();
	add_money("silver",15);
}
void init()
{
	object me, ob;
	mapping fam;

	::init();
	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& ((fam = ob->query("family")) && fam["family_name"] != "���չ�" )
	&& me->query("biao/owner"))
	{
		if( !ob->query_temp("warned") ) {
		command("say ����������˲��ý������չ��������뿪��");
			ob->set_temp("warned", 1);
	}
		else if( ob->query_temp("stay")<5 ) ob->add_temp("stay",1);
		else {
			command("say �󵨿�ͽ�������ô����չ�������\n");
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}
	remove_call_out("checking");
	call_out("checking", 1, me);
}

string ask_escape()
{
	mapping fam;
	object ob;

	ob=this_player();
	if (!(fam = ob->query("family")) || fam["family_name"] != "���չ�")
		return RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��";

	if((ob->query("job_status"))==1)
	{
		command("say �ðɣ������ڿ������ˡ�");
		add("job_count", -1);
		ob->set("job_status",0);
	}
	else  
		command( "say ����û�������￴�ش��ţ��⻰�Ӻ�˵��");
		
	return "���Ҫ�úøɣ�\n";
}

string ask_job()
{
	mapping fam;
	object ob;
	
	ob=this_player();

	if (!(fam = ob->query("family")) || fam["family_name"] != "���չ�")
		return RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��";

	if((ob->query("job_status"))==2)
		return "�㻹û�����ͯ�ѵĹ�����������ʲô��\n";

	if((ob->query("combat_exp"))<10000)                             //      exp<10k  can not do meijian's job; 
		return "�㾭�鲻�����ڴ�������Σ�ա��Ⱦ��鹻���������ҡ�\n";

	if((ob->query("job_status"))==1)
	{
//		command("say ���¿�ʼ�ɡ��úøɣ�");
//		remove_call_out("doing_job");
		command("say �����ɲ������ɸ���Ļ����ֱ�Ӹ���˵��ɲ��ˡ�");

	}
	else  if(query("job_count")>=4)
		  return "�������ˣ����ŵ�λ���Ѿ��������ˡ���һ������������\n";
    else{
		command( "say ��������￴�ش��Űɡ�");
		ob->set("job_status", 1);
		add("job_count",1);
	 }

	
	if(random(4)==1)
		call_out("add_bandit",0,ob); //bandit has 1/4 chance;

	call_out("doing_job",500,ob); //use call out and set time 10 minitues.
	return "�����񣬲�Ҫ͵����\n";
}

int doing_job(object ob)//, int second)
{
	if((ob->query("job_status"))==1)
	{
	ob->add("combat_exp", 50+random(100));
	ob->add("potential",50 + random(50));

	if ( ob->query("potential") > ob->query("max_potential") )
	ob->set("potential", ob->query("max_potential"));

	ob->set("job_status",0);

	command("say ʱ�䵽�ˣ�"+ob->query("name")+"����������ˡ����Ҫ���Ŭ����");
	add("job_count", -1);
	}
	return 1;
}

int add_bandit(object ob)               //if bandit come, player can 'ask mei about �ɲ���' and then escape.
{
	object me;
	object *inv;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

//              write("begin load bandit\n"); //for test;

	me = load_object("/d/lingjiu/npc/bandit");
	me->move("/d/lingjiu/damen");
			
//              write("finish load bandit\n"); //for test;
/* delete and copy skills */

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]/4*5);
		}
	}

/* delete and copy skill maps */

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}

/* delete and copy skill prepares */

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}

	hp_status = ob->query_entire_dbase();

	me->set("str", hp_status["str"]-2+random(4));
	me->set("int", hp_status["int"]-2+random(4));
	me->set("con", hp_status["con"]-2+random(4));
	me->set("dex", hp_status["dex"]-2+random(4));

	me->set("max_qi",    hp_status["max_qi"]/5*7);
	me->set("eff_qi",    hp_status["max_qi"]/5*7);
	me->set("qi",        hp_status["max_qi"]/5*7);
	me->set("max_jing",  hp_status["max_jing"]/5*7);
	me->set("eff_jing",  hp_status["max_jing"]/5*7);
	me->set("jing",      hp_status["max_jing"]/5*7);
	me->set("max_neili", hp_status["max_neili"]);
	me->set("neili",     hp_status["max_neili"]);
	me->set("jiali",     hp_status["jiali"]/2);
	me->set("combat_exp",hp_status["combat_exp"]/7*9);
	me->set("shen",      hp_status["shen"]*(-1));
	
//		write("ͻȻ,�Ӻ���������һ�������!\n");
//	write( "�����˳��һ������,ָ�����:������!\n" );
	message_vision(HIR"ͻȻɽ�³���һ��$N��������˵�������Ƿ��𹥻���\n"NOR, me);
	message_vision(CYN"$N���һ�������ȵ����Ͽ��ͯ�ѽ����������Ľ�ҩ����\n"NOR, me);

	me->kill_ob(ob);
	
		return 1;
		    
    
}

int do_kill(object me, object dest)
{

//      write("begin kill bandit\n"); //for test

	if( objectp(dest) && present(dest, environment(me))
		 && !environment(me)->query("no_fight"))
	{
		command( "say �󵨿�ͽ�����������չ���Ұ��������츿�־��ܣ�");
		me->kill_ob(dest);
		dest->fight_ob(me);
	}
	
	call_out("checking", 0,  me, dest);
	
	return 1;
}

int checking(object me)
{
	object ob;

//      write("begin check bandit\n"); //for test

	if (me->is_fighting()) 
	{
		call_out("checking", 1, me);
	    return 1;
	}

	if( objectp(ob = present("bandit", environment(me))))
	{
		call_out("do_kill", 1, me, ob);
	return 1;
	}
	
	call_out("checking", 1, me);
	return 1;
}
#include "/kungfu/class/lingjiu/jianbi.h"
#include "/kungfu/class/lingjiu/auto_perform.h"