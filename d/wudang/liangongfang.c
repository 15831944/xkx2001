//Cracked by Roath
// liangongfang.c ������
// by Xiang
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������������ҵط��ż������ţ���λ�䵱��������ϥ������
�������
LONG
	);
	set("exits", ([
		"south" : __DIR__"donglang1",
	]));
	set("objects", ([
		"/d/village/obj/zhujian" : 3]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}
