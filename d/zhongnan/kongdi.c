//Cracked by Roath

// road: /zhongnan/kongdi.c

inherit ROOM;

void create()
{
        set("short","�յ�");

        set("long",@LONG
��������ɽɽ������һ��յأ�����ƽ̹������һ��С·ֱ��ɽ赶�
�ϣ�ͨ��������ɽ���塣�ϱߺ�����һ��Ƭ���֣�ֻ���������������д�
����������һ��ɽ·�����Ϻ�������һ��С����
LONG);

        set("exits",([ "northup" : __DIR__"shanlu12",
                        "west" : __DIR__"milin1",
				"south" : __DIR__"milin2",
                      ])
           );
	  set("cost",1);
	  set("outdoors", "zhongnan");

        setup();
        replace_program(ROOM);
}

