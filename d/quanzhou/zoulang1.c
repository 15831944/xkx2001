//Cracked by Roath
// Room: zoulang1.c ���ȣ�
// qfy July 7, 1996.

inherit ROOM;

void reset();
int valid_leave();

void create()
{
    set("short", "����");
    set("long", @LONG
�������Զ��а�ǽ������Ժ��������������ǡ����в�������������ѧ��
������Ժ�ǡ����Ȳ�������ѧ�������ȷ���
LONG
    );

    set("exits", ([
	"north" : __DIR__"daobu",
	"south" : __DIR__"bangbu",
	"east" : __DIR__"qianting",
	"west" : __DIR__"zoulang2",
    ]));

    set("no_clean_up", 0);

	set("cost", 1);
    setup();
    //replace_program(ROOM);
}
