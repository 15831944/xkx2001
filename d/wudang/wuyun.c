//Cracked by Roath
// wuyun.c ���������¥
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "���������¥");
	set("long", @LONG
���������¥�������أ������ʮ�������ʽ����ص����������һ��֧
�ţ��������ġ�һ��ʮ����������˵������ʱ�ڴ˶��飬������ʮ�������
�����Ԣʸ־���壬�ճɶ���֮�š������︩�Ⱥɽ���������룬����Ϊ��
���Ž������漣��
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"taizipo",
	]));
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

