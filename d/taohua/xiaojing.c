//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ���ɴ�����ʯ�̳ɵ�С·���䲻��˵��һ����Ⱦ����Ҳ������࣬
�����������˴�ɨ����������һ��С����������һ��ݵأ�������һ�����֡�
LONG
	);
	 set("exits", ([
                "west" : __DIR__"caodi",
                "east" : __DIR__"shulin",
                "north" : __DIR__"tuqiu",
		"south" : __DIR__"haitan",
        ]));
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
