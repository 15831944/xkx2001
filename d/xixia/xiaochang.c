//Cracked by Roath
// Room: /d/xixia/xiaochang.c

inherit ROOM;

void create()
{
	set("short", "СУ��");
	set("long", @LONG
����������Ӫ��СУ����ƽʱ��ʿ�Ǿ���������������Ϻ�ƽ����
������ָ��̨���и��������ɵ���ˣ��˶�һ������һ������������
Ӫ��ɫ����ӭ���������졣ƽʱ��ʿ��һ�����������ϳ��٣������
����������Ұս����������ʳ����Ѳ�ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"biaoqiyin",
]));
	set("objects", ([
		__DIR__"npc/xxbing2" : 3,
	]));
	set("cost", 1);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
