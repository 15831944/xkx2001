//Cracked by Roath
// Room: jianbu.c ���Ȳ�
// qfy July 30, 1996.

inherit ROOM;

void create()
{
    set("short", "���Ȳ�");
    set("long", @LONG
������ݵİ��Ȳ����ɳ�䰸��𡣵�������ľ��ɳ�����ɹ���ϰ��
LONG
    );

    set("exits", ([
	"north" : __DIR__"zoulang1",
    ]));

    set("objects", ([
	__DIR__"npc/chenhu" : 1,
    ]));		    	

    set("no_clean_up", 0);

	set("cost", 0);
    setup();
    //replace_program(ROOM);
}
