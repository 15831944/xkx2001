//Cracked by Roath
// shizhu.c ʯ�� 
// by Fang 8/19/96
// modified by Ryu 6/15/97;
// xQin 8/00

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
�������ҹ�ǰ��һ��ʯ����������Σ����ͱ��Ϻ��������������졣����
��һ��¯���ڴ������Ϊ������ͷ�㡱������͵������Ը��ʯ��������������
���޷�����ǰ�а������ƣ�����������Ԩ����һʧ�㣬��ʬ���޴档
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northup" : __DIR__"nanyanfeng",
	]));
	set("cost", 9);
	setup();
}
void init()
{
	add_action("do_mianbi","���");
        add_action("do_mianbi","mianbi");
}
int do_mianbi()
{
	object me, mengzhu, room;
	int shen, ep, gain;
	me = this_player();
	shen = me->query("shen");
	ep = me->query("combat_exp");

        if (me->is_busy()
        || me->query_temp("pending/exercising")
        || me->query_temp("exit_blocked"))
                return notify_fail("��������æ���ء�\n");

	if (me->query("jing") < 200 || me->query("jingli") < 200)
	return notify_fail("����÷��겻�������Ծ۾��붨��\n");
	
        message_vision("$N�����ʯ��������˼�����ã���������\n", me);

	me->start_busy(8);
        me->set("jing",1);
	me->add("jingli", -200);

	if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");
        seteuid(getuid(me));
        if( !objectp(mengzhu = present("mengzhu", room)) ){
        mengzhu = new("/clone/npc/meng-zhu");
	mengzhu->move("/d/taishan/fengchan");
	}

        if (userp(me) && me->query("id") != mengzhu->query("winner") ){
        if (shen > 10000 && shen > ep){
	gain = (shen - ep) * 1000 / ep; 

	if (gain > 20) gain = 20;

	if (me->query("family/family_name") != "�䵱��") gain = gain/4;

	me->add("combat_exp", gain * 8 + random(gain*4));
	me->set("shen", me->query("combat_exp"));

	if (me->query("family/family_name") == "�䵱��")
	me->add("potential", gain * me->query_skill("taoism") / 25
	+ random(gain*me->query_skill("taoism")/60));

	if (me->query("potential") > me->query("max_potential"))
	me->set("potential", me->query("max_potential"));
	}
    }
        return 1;
}

