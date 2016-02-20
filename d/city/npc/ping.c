//Cracked by Roath
// ping.c ƽһָ

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("ƽһָ", ({ "ping yizhi", "ping", "yizhi" }));
	set("title", "ҩ���ϰ�");
	set("nickname","ɱ����ҽ");
	set("gender", "����");
	set("long", "������ҽ���߳��ġ�ɱ����ҽ��ƽһָ���������Ը�Ź֣�����ʲô�˶�ҽ�ġ�\n");
	set("age", 65);

	set("int", 30);
	
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);

	set("combat_exp", 50000);
	set("attitude", "peaceful");

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 140);
	set_temp("apply/defense", 140);
	set_temp("apply/damage", 50);

	set("vendor_goods", ({}));

	setup();
	add_money("gold", 1);
}

void init()
{
	object ob;

	::init();
        if( present("shou jiao", this_player()) && !this_player()->query_temp("jiao_giver") ) {
		message_vision("\nƽһָͻȻ�ع�ͷ����Ŀ�⾼���ص���$N������˵�����������Ͽ��м��󱦱�ѽ��Ը���������𣿡�\n" +
				   "����˵�����������֣������Ź⣬¶����Ϊ�����˷ܵ����顣\n\n", this_player());

		ob = new("/clone/money/thousand-cash");
		ob->set_amount(3);
		ob->move(this_player());

		message_vision("���Ҹ�����ǧ����������ô�������� ƽһָ����$N��Ӧ���������ͳ�һ����Ʊ������$N���С�\n", 
					this_player());
	}
}

int accept_object(object ob, object obj)
{
	object me = this_object();

	if( obj->query("id") == "shou jiao" && ob->query_temp("jiao_giver") ) {
		message_vision("\nƽһָ΢Ц��������С�ӣ��Ե�һ�ᣬ�����������һ�ű�ˮ���飡\n", ob);
		message_vision("\nƽһָת���߽�ҩ�����á�\n", ob);
		call_out("do_make", 60, this_object(), this_player());
		return 1;
	}

	if( obj->query("id") == "shou jiao" && !ob->query_temp("jiao_giver") ) {
		message_vision("\nƽһָ����һ�����ӹ��޽ǣ���Ҳ�Ƶ��ܵ�ҩ���ԣ�����һ�������У����޽����˽�ȥ�����������á�\n", ob);
		ob->set_temp("jiao_giver", 1);
		return 1;
	}

	if( obj->query("id") == "thousand-cash" && obj->query_amount() == 3 && ob->query_temp("jiao_giver") ) {
		message_vision("\nƽһָ�������ɵص���$N���˰��á�˵�������㲻��Ǯ���� ���㵽����Ҫʲô�� �㵹˵˵����\n", ob);
		ob->set_temp("cash_giver", 1);
		add_action("do_say", "say");
		return 1;
	}

	return 0;
}

int do_say(string arg)
{
	object me, ob;

	ob = this_player();
	me = this_object();
		
	if( !ob->query_temp("jiao_giver") || !ob->query_temp("cash_giver") ) return 0;

	if( arg=="��ˮ����" ) {
		message_vision("\nƽһָ��Ц������һ���޽�ֻ����һ�ű�ˮ�飬���ܵ�ʲô�ô����� ���������ٸ���Ūһ��������\n", ob);
		return 1;
	}
	else	message_vision("\nƽһָб�ۿ���$N����Ц�������Ҳ�������˵Щʲô����\n", ob);
	
	return 0;
}

int do_make(object me, object ob)
{
	object zhu;

	message_vision("\nƽһָ���˳�����˵��������ˮ���������ˣ���͸���ɣ� ǰ;���أ���\n", ob);
	command("hehe");

	zhu=new("/d/shaolin/obj/pishui-zhu");
	zhu->move(ob);

	message_vision("\nƽһָ����$Nһ�ű�ˮ���顣\n", ob);
	return 1;
}
