//Cracked by Roath

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������һ���ؽѣ�������ҩ���ղ����ҩ��ĵط�������һ��
����ӣ�����ҩ�ĺ�����С��ƿ��������һֻ��ҩ¯�������о���ҩ
ζ��
LONG
	);
	set("no_clean_up", 0);

    set("objects", ([
         __DIR__"obj/yaolu" : 1,
]));
	setup();
}


void init()
{
	add_action("do_turn","zhuan");
	add_action("do_turn","turn");
	add_action("do_search","search");
}

int do_turn(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg == "" ) return 0;
	if( arg == "ball" || arg == "qiu")
	{
		message_vision("$N�������ϣ����α���������һת��ͷ�Ͽ���һ�����
�\n���Ӵ���$N������ȥ��\n",me);
		me->move(__DIR__"neitang");
		return 1;
	}
	else
		return notify_fail("��Ҫ��ʲô��\n");
}

int do_search(string arg)
{
	object ob,me;
	me = this_player();
	if (!arg || arg == "") return 0;
	
	if (arg == "jia" || arg == "shelf")
	{
		if (query("searched"))
			return notify_fail("���ڼ����Ϸ�Ѱ��һ�󣬵�ʲô��û�ҵ���\n");

		switch (random(7))
		{
			case 0:
			ob = new("/d/dongtinghu/obj/yangxin");
			break;
			case 1:
			ob = new("/d/dongtinghu/obj/jinchuang");
			break;
			case 2:
			ob = new("/d/dongtinghu/obj/baicao-dan");
			break;
			case 3:
			ob = new("/d/dongtinghu/obj/yulu-wan");
			break;
			case 4:
			ob = new("/d/dongtinghu/obj/xxqingxin-san");
			break;
			case 5:
			ob = new("/d/dongtinghu/obj/heishi-dan");
			break;
			case 6:
			ob = new("/d/dongtinghu/obj/dali-dan");
			break;
		}

		set("searched",1);		
		message_vision("���һ��Сƿ�����ҵ�һ��"+ob->query("name")+"��\n",me);
		ob->move(me);
		return 1;
	}
}	

