//Cracked by Roath
// /d/xueshan/dumudian.c
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ĸ��");
        set("long", @LONG
�����Ǵ����µĶ�ĸ�������������𣬾�Ϊ�����١�����
̻�����ġ�����������ִ��ӡ���������졣���ڶԳ������ĸ�������
�ϵ��̶��ƣ��¿������ơ������Ϲ�������������ͷ��������
ħ������
LONG
        );
        set("exits", ([
				"north" : __DIR__"changlang",
                "southdown" : __DIR__"yanwu",
        ]));
	set("objects", ([
		__DIR__"npc/zrlama": 1,
		__DIR__"obj/tonggang": 1,
	]));

	set("cost", 1);
    setup();
}

void reset()
{
	::reset();
	set("no_clean_up", 1);
}
