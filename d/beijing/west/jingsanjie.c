//Cracked by Roath
// Room: /d/beijing/west/jingsanjie.c

inherit ROOM;

void create()
{
	set("short", "景山街");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"gulou",
  "east" : __DIR__"huoshenmiao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
