//Cracked by Roath
// room: /d/baituo/base1
// ���ոİ�
// maco 2/17/2000
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ܽ�");
        set("long", @LONG
�������ֲ�����ָ��ֻ�������������������䶯��������
LONG
        );
        set("exits", ([ 
	    "up" : __DIR__"lingshege",
	    "north" : __DIR__"base2",
        ]));
        set("objects", ([ 
	    __DIR__"npc/snake" : 3,
		"/d/foshan/npc/zsnake" : 2,
         ]) );
        replace_program(ROOM);
	create_door("up", "�ܽ�ʯ��", "down", DOOR_CLOSED);
	set("cost", 0);
        setup();
}
