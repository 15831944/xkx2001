//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
һ��������������������ʨ�Ӹ��񣬰˼���ͼ����"�֡��ݡ�ɡ���ǡ�
����ƿ���㡢�����"���ֱ����������档���ײ������������������
���Ϻ�������ɲ���Ƕ�������¹�ʮ���㣬��Ϊ "ʮ����"����ƿ���б�
�ǣ������б��顣
LONG
        );
        set("exits", ([
                "east" : __DIR__"frontyard",
        ]));
	set("objects", ([
                "/clone/weapon/falun" : 1,
        ]));
	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
