//Cracked by Roath
// Room: jianbu.c ����
// qfy July 30, 1996.

inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
������ݵĽ����������������𡣵���������Ͳľ�ˣ��ɹ���ϰ��
LONG
    );

    set("exits", ([
	"north" : __DIR__"zoulang2",
    ]));

    set("objects", ([
	__DIR__"npc/liuhongying" : 1,
    ]));		    	

    set("no_clean_up", 0);

	set("cost", 0);
    setup();
    //replace_program(ROOM);
}
