//Cracked by Roath
// Room: daobu.c ���в�
// qfy July 30, 1996.

inherit ROOM;

void create()
{
    set("short", "���в�");
    set("long", @LONG
������ݵĵ��в����������������ܶ���ľƬľ�ˣ��ɹ���ϰ��
LONG
    );

    set("exits", ([
	"south" : __DIR__"zoulang1",
    ]));

    set("objects", ([
	__DIR__"npc/longquan" : 1,
    ]));		    	

    set("no_clean_up", 0);

	set("cost", 0);
    setup();
    //replace_program(ROOM);
}
