//Cracked by Roath
// xuanwumen.c ������
// by Xiang

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
	�������ǰ��һ���ߴ��ʯ��������д�š������š������ֽ���֣���
�������Զ���þ���ɹ���ܣ��Ѿ��Ե���Щ��������������һ�����ۣ���������
һ��ʯ��·һֱͨ��ɽ�¡�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"shijie3",
		"southup" : __DIR__"guangchang",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/zhike" : 1]));
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

