//Cracked by Roath
// room: /d/xingxiu/btbarn
// Jay 10/18/97

inherit ROOM;

void create()
{
        set("short", "�ܽ�");
        set("long", @LONG
�������ֲ�����ָ��ֻ�������������������䶯��������
LONG
        );
        set("exits", ([ 
	    "south" : __DIR__"btbase",
        ]));
        set("objects", ([ 
	    __DIR__"npc/snake" : 2,
		"/d/foshan/npc/zsnake" : 1,
         ]) );
        replace_program(ROOM);
	set("cost", 0);
        setup();
}

