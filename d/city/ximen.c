//Cracked by Roath
// Room: /city/ximen.c
// YZC 1995/12/04 

#include <ansi.h>;
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long",
"���������ţ�����ǰ�����⵽���˵Ĺ�������Ե���Щ�ưܡ��������Ϸ�
����ǿǿ�����ϳ���"+YEL"����"NOR+"���������֣���ǽ�����ż���"+HIW"ͨ����ʾ"NOR+"(gaoshi)������
���ﷸ��������ıؾ�֮�أ��ٱ��ǽ䱸ɭ�ϣ��������ͽ�ס�������ʡ�һ����
ֱ����ʯ���������������졣�����ǽ��⣬����ġ����εġ���·�ģ�����
�Ҵҡ���ӿ��˽Ų������¹ٱ��Ҳꡣ�����ǳ��\n"
	);
        set("outdoors", "city");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east" : __DIR__"xidajie3",
  		"west" : "/d/xingxiu/xxroad1",
		"north" : __DIR__"xijiao1",
		"south" : __DIR__"xijiao3",
	]));

        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
               "/clone/npc/murong" : 1,
        ]));
	set("cost", 1);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n�㽭�ᶽ\n�����\n";
}
int valid_leave(object me, string dir)
{
        if (dir =="east" )
        if(present("guan bing", (environment(me)))
        && me->query_condition("killer") > 0)
                return notify_fail("�ٱ����еĵ���ס�����ȥ·��\n");
        return ::valid_leave(me, dir);
}
