//Cracked by Roath
// Ssy

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"ѩ��"NOR);
        set("long", @LONG
����������㼫Ŀ��ȥ��Ψ��һƬ��ãã�Ĵ�ѩ���㲻������һ
˿���⡣    
LONG
        );
        set("exits", ([
                "southdown" : __DIR__"suolong",
                "northup" : __DIR__"snow2",
        ]));
        set("cost", 1);
        set("outdoors", "tianshan");
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "northup") {
                me->add("jing", -30);
                me->add("jingli", -30);
		message_vision(HIR"$N����ðѩ��Ŭ�������ʵǡ�\n"NOR, me);

        }
        return 1;
}
