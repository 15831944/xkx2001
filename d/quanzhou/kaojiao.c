//Cracked by Roath
// kaojiao.c ���̳�
// qfy July 30, 1996.

inherit ROOM;

void create()
{
        set("short", "���̳�");
	set("long", @LONG
��������ݵĿ��̳�������������������ӵ��ڴ�ϰ�䣬ȭ����ߣ�
�赶Ū����ˣǹ�Ӱ��ĺò����֡��������̳�������ݵ�ǰ����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "west" : __DIR__"qianting",
            "east" : __DIR__"wgdamen",
        ]));

	set("objects", ([
	    __DIR__"npc/xuetu" : 3,	
	]));

        set("no_clean_up", 0);
        set("outdoors", "city" );

	set("cost", 1);
        setup();
        //replace_program(ROOM);
}
