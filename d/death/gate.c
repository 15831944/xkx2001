//Cracked by Roath
// gate.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW "���Ź�" NOR);
	set("long", 
		"�������������������ڡ����Źء���������ǰ������һ���ߴ��\n"
		"��ɫ��¥����\���������޿�������ж�ǰ������Ϊһ�����Źؾ��޷���\n"
		"�������ˡ�\n");
	set("exits", ([
		"north" : "/d/death/gateway",
	]) );
	set("objects", ([
		__DIR__"npc/wgargoyle":1
	]) );
	set("no_fight", 1);
	set("cost", 0);
	setup();
}

void init()
{

	object *inv, me=this_player();
        int i;

        inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]->is_character())continue;
                destruct(inv[i]);
                }

	me->clear_condition();

	if ( me->query_temp("sanxiao") )
	{
        me->delete_temp("sanxiao");
	me->delete_temp("smile");
	}

	add_action("do_suicide","suicide");

}

int do_suicide(string arg)
{
        object me = this_player();
        tell_object(me, "�㻹�����ء�\n");
        return 1;
}


