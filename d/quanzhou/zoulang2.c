//Cracked by Roath
// Room: zoulang2.c ���ȣ�
// qfy July 30, 1996.

inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
�������Զ��а�ǽ������Ժ��������������ǡ�������������������ѧ��
���ַ�����Ժ�ǡ�����������ѧ��������������һ����Ϣ�ҡ������ߴ�������
�������ض��ǳ������ڡ�������ǽ���пھ���
LONG
    );

    set("exits", ([
	"north" : __DIR__"anqibu",
	"south" : __DIR__"jianbu",
	"east" : __DIR__"zoulang1",
	"west" : __DIR__"xiuxishi",
	"northwest" : __DIR__"chufang",
    ]));

    set("no_clean_up", 0);
    set("resource/water", 1);	

	set("cost", 1);
    setup();
    //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("mark/��") && dir == "west" )
		return notify_fail("����������������ס�����\n");

	return ::valid_leave(me, dir);
}
