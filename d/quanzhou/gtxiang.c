//Cracked by Roath
// gtxiang.c ��̳��
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��̳��");
	set("long", @LONG
��̳��˳��ʩ����ǽ���Ѷ�����һ����������ˮ�Ĺ������İ���������̳
����������ǳ����¡�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"southwest" : __DIR__"chengtian",
		"north" : __DIR__"jiangfu",
		"west" : __DIR__"xuetang",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
