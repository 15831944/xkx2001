//Cracked by Roath
// changle/clzoulang2.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����������������Щ�����治�ϴ���������֮������ʱ������
��ŭ��ͼ�С������������̾Ƶ���ζ�������Ե����ǰ��࣬������
һЩ����Ĳи�ʣ�ˡ�
LONG );

        set("exits", ([
		"south" : __DIR__"clzoulang1",
		"north" : __DIR__"clxiaoting",
		"east" :  __DIR__"clhuayuan",
		"west" :  __DIR__"clxiaowu",
        ]));

        set("cost", 0);

        setup();
        replace_program(ROOM);
}

