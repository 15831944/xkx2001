//Cracked by Roath
// Room: yuzf.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǳ�������֮һ��������ʯ�壬��������Ʒ�������·�̡��˷�
���ʣ���һ��������������������أ��߲����ʣ���ν���Ʒ�֮�������˷�
ɽ·��᫣��ұ���·������Ϊ��ɽ�����һ�����ϡ�
LONG	);

	set("exits", ([ 
              "northwest" : __DIR__"lumf",
              "eastdown" : __DIR__"tianchi",
              "northeast" : __DIR__"baiyf",
              "southeast" : __DIR__"tiyf",
        ]));

        set("objects",([
                __DIR__"npc/tian" : 1,
        ]));
	
        set("outdoors", "changbai");

        set("count", random(3)+1);

	setup();
}
