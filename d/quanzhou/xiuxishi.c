//Cracked by Roath
// Room: xiuxishi.c �����Ϣ��
// qfy July 7, 1996 

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�����Ϣ��");
        set("long", @LONG
����������ݵ���Ϣ�ҡ���ʰ�÷ǳ��ɾ�������򵥡���ǽ���м���ľ����
���Ŵ�����һ�����ӡ�
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);

	set("exits", ([
	    "east" : __DIR__"zoulang2",
	]));

	set("cost", 0);
        setup();
	replace_program(ROOM);
}
