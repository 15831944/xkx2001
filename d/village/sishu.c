//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "˽��");
        set("long", @LONG
���Ǵ����һ����ª��˽�ӣ����º�ͯ���ڴ��ϿΡ������Ҳ�Ǵ�����ˣ�
ƽʱ����ѧ�⣬Ҳ��������������д���ż������Էǳ������𾴡�˽�������
�򵥣��ɼ��ŷ��������ŵ��ӣ����ʹպ�������������������������鼮������
�����Ҳȷʵ���м���īˮ��
LONG
        );
        set("exits", ([
                "east" : __DIR__"sroad2",
        ]));
	set("objects",([
                "/d/city/npc/xiucai" : 1,
        ]));

	set("cost", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        me->set_temp("mark/��", 0);
        return 1;
}
