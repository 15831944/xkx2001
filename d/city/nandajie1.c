//Cracked by Roath
// Room: /city/nandajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�ϼ���");
	set("long", @LONG
�ϴ�����ǳ���ķ����ضΣ�һ�����ϣ�һƬ�ƺ���̣��ǳ����֡�Ц����
���������������������һƬ��������Ķ��䣬�㲻����Գ��������ʹ�ͣ��
����һ����������һ�����ֵĹ㳡��������һ�ҵ��̣�ǽ��д��һ�����ġ�����
�֣���ϸ������������Լ�������ּۻ��۵���������������һƬ�����������š�
һ��һʮ������Ǯ����ԭ�����Ƿ�Բǧ��֮������һ�Ҷĳ���������һ�Һ���
�ĸ�¥�����������½��ľ۽��
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"dangpu",
		"south" : __DIR__"nandajie2",
		"west" : __DIR__"duchang",
		"north" : __DIR__"guangchang",
	]));
        set("objects", ([
                __DIR__"npc/xunbu" : 1,
        ]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

