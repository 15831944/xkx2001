//Cracked by Roath
// jindian.c ��� 
// by Fang 8/20/96

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"���"NOR);
	set("long", @LONG
����м乩��������ͭ���������㣬��̬�����������н�ͯ��Ů������
�Ϲ�����ˮ�������������ׯ�ϡ���ǰ������Ϊͭ��������͵���ͭ�񡢹�
��í��һ�壬������ȷ�����ɸ߳���
LONG
	);
//        set("outdoors", "wudang");

	set("exits", ([
		"north" : __DIR__"zijin",
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

