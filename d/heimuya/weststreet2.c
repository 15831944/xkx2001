//Cracked by Roath
// Room: /d/heimuya/weststreet2.c
// Date: fear 1999/12/08

inherit ROOM;




void create()
{
        set("short", "������");
        set("long", @LONG
����ƽ���ݵ������֣���Χ�кܶ���̣���������
�ľ����������������ˡ��������ƽ���͵����ǡ�
LONG
        );

        set("exits", ([
                "east" : __DIR__"weststreet1",
                "north" : __DIR__"majiu",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

