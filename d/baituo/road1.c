//Cracked by Roath
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
һ�������С�������洫����˻˻�������졣
LONG
	);
	set("exits", ([ 
	    "north" : __DIR__"barn",
	    "south" : "/d/xingxiu/btyard",
	]));
	set("outdoors","baituo");
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
