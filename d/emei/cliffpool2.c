//Cracked by Roath
// d/emei/cliffpool.c ˮ̶
// xbc: 96/02/02

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ˮ̶");
	set("long", @LONG
����һ����ˮ̶��̶��ˮ�����ޱȣ�һ�¾Ͱ��㼤���ˡ�̶ˮ��������
��ȥ������ɽʯ���ͣ�ɽ��������Ρ���֪�����������أ�
LONG
	);
        set("no_clean_up", 0);
        set("outdoors", "emei" );
	set("cost", 6);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");

	object me = this_player();
	object *inv;
	int i, flag;
	
	inv = all_inventory(me);	
	flag = 0;
	for (i=0; i < sizeof(inv); i++) 
		if ( !inv[i]->query("armor_prop/armor") ) {
			destruct(inv[i]);
			flag += 1;
		}

	if ( flag ) write(HIB"�����ϵ�Ǯ�ﶼ����ˮ�У���Ҳ�Ҳ����ˣ���\n"NOR);

}

int do_climb(string arg)
{
	object me = this_player();

	if ( arg && arg != "up")
		return notify_fail("ʲô��\n");

	if ( arg == "up" ){
                message_vision("$N������ȥ��\n", me);
       		me->move(__DIR__"qingyin");
                message_vision("$Nˮ���ܵشӽ�������������\n", me);
	        return 1;
	}
	return 0;
}


