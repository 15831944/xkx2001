//Cracked by Roath
// Room: /city/xidajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣��������������ڣ�����ϡ
�٣������ĵغ������塣������������Է���в��ٷ���֮ʿ�ۼ������������
��Ӫ�����ϱ߾��������ˡ�
LONG );
        set("outdoors", "city");
        set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"xidajie1",
                "north" : __DIR__"bingyindamen",
                "west"  : __DIR__"xidajie3",
                "south" : __DIR__"yamen",
        ]));

        setup();
        replace_program(ROOM);
}

