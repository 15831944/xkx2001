//Cracked by Roath
// Room: /d/beijing/zijincheng/shenwumen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ͻ��ǵĺ��ţ��������ͳ����Ͻ��ǡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"shunzhenmen",
  "west" : __DIR__"tongdao8",
  "east" : __DIR__"tongdao7",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
