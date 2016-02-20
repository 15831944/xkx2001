// Room: /d/wiz/courthouse.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�����������е���ʦ���ʻ����˵ķ�Ժ����һ���Ǳ��˼�ٻ���
��Ϊ̫������ˣ��Ż�������������𲻳����йٵ��������⣬��
�����ϼǺţ��������ε��˽��ᱻ���Լ��̣��úûش�ɡ�
LONG
	);
	set("no_fight", 1);
	set("no_sleep_room",1);
	set("objects", ([
		__DIR__"npc/judge":1 ]) );

	set("cost", 0);
	setup();
}

void test_me(object me)
{
	me->set_temp("old_startroom", me->query("startroom"));
	me->set("startroom", __FILE__);
	me->set_temp("last_location", base_name(environment(me)));
	message_vision(HIW"��Ȼ���ϵ��¸�������������$N�Ĳ��ӣ��������һֻľ�ƻ�е�֣���$Nǣ���ˡ���\n"NOR, me);
	me->move(this_object());
}
