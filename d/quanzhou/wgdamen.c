//Cracked by Roath
// Room: /city/wgdamen.c
// qfy 1996/7/30 

inherit ROOM;

void create()
{
	set("short", "��ݴ���");
	set("long", @LONG
һ�����ɻԻ͵���ݡ���������Ա߰�������ͷ�ߴ����ͣ�����������ʯ
ʨ�ӡ����Ϲ���һ��ڵ״��Ҷ�ĸ�ˢ��Ĵ��֣���������ݡ��������⡣
��߲���һ�����ɶ�ߵ���ˣ����š��䡱�ֵĺ������Ʈ�����ǳ�����
�����ϣ�������������ݣ��ö���е��ӵܶ��ڴ�ѧЩȭ�ű������򡣹�����
��º����ÿͣ������ϳ�֮�硣��Ƹ��ͷ����һ��һ����湦��ĺ��֡�
LONG
	);

	set("exits", ([
		"east" : __DIR__"minzai2",
		"west" : __DIR__"kaojiao",
	]));

	set("objects", ([
		__DIR__"npc/mending" : 2,
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
