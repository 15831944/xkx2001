//Cracked by Roath
// /d/emei/xixiang.c ϴ���
// Shan: 96/06/22

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ϴ���");
	set("long", @LONG
ϴ���ԭֻ��һͤ��ͤǰ��һ��ʯ����С��(pool)���ر߲�Զ����Σ�ҡ�
ϴ���Ԣ��һƬ��ɼ���У��������������ɽ������������������̿���
���������ʱ�����������ţ�������ޣ����������칬����������������
�������ġ���س�ҹ�����ɴ��������ʣ������׶�ƺ������������ʯ��
LONG
	);
	set("exits", ([
		"southup" : __DIR__"lingyun",
		"eastdown" : __DIR__"po2",
	]));

        set("resource/water", 1);

        set("item_desc", ([
		"pool" :
"����һ��ʯ��������С�أ���˵���ͳ������ˣ������ڴ˳���ԡ���󣬶����\n"
"�����𶥣���Ϊ��ϴ��ء���\n",

		"Σ��" :
"Σ�ұ߿��С��ҹ���⡹�ĸ����֡���������Ϊ���ƻ��ƣ��Ѽ���ס�\n",

		"rock" :
"Σ�ұ߿��С��ҹ���⡹�ĸ����֡���������Ϊ���ƻ��ƣ��Ѽ���ס�\n"

])  ) ;

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 2);
	setup();
//	replace_program(ROOM);

}

void init()
{
	object *inv = all_inventory(find_object("d/emei/xixiang"));
	object comer = this_player();
	int i;

	add_action("do_swim", "swim");
	add_action("do_swim", "dive");
	if ( (string)comer->query("race") == "����" )
		for ( i=0 ; i < sizeof(inv); i++)
			if ( inv[i]->query_temp("xixiang_swimming") ) {
				if ( inv[i]->is_spouse_of(comer) ) {
					tell_object(inv[i], HIB"�㷢�������ߵ��رߣ���ϸһ����ԭ�������"
							+ inv[i]->query("spouse/title")
							+ "���龪һ����\n"NOR);
					message("vision",CYN + comer->name()
							+ "��������ĵ�һЦ��\n"NOR, inv[i]);
					message("vision",CYN"�����" + inv[i]->name()
							+ "���ĵ�һЦ��\n"NOR, comer);
				}
				else if ( (string)inv[i]->query("gender") != "Ů��"
					|| (string)comer->query("gender") == "Ů��" ) {
					tell_object(inv[i], RED"��ͻȻ����������·�����ŵøϽ�������أ��޲����Ҹ��ط����ȥ��\n"NOR);
					tell_object(comer, RED"�����һ���˻Ż����ŵش�ϴ���������������\n"NOR);
					inv[i]->delete_temp("xixiang_swimming");
					inv[i]->set("jing", 0);
					inv[i]->start_busy(1);
				}
				else {
					tell_object(inv[i], RED"��ͻȻ����" + comer->name()
						+ "�����㲻������ؿ��ӣ����ŵü���Ҫ���˹�ȥ��\n"NOR);
					tell_object(comer, RED"��ͻȻ�����������Ů����ԡ��������Ҫ�����ŵ����˹�ȥ��\n"NOR);
					inv[i]->delete_temp("xixiang_swimming");
					inv[i]->set("jing", 0);
					inv[i]->start_busy(1);
					if ( random(inv[i]->query_per()/6) ) inv[i]->unconcious();
				}	
			}
}

int do_swim(string arg)
{
	object me = this_player();
	object *inv;
	int i, flag;
	int t; // time of the day in minutes
	mixed local;
	
	if ( !arg || (arg != "pool" && arg != "ϴ���") ) {
		return notify_fail("ʲô��\n");
	}

	if ( me->query_temp("xixiang_swimming") )
		return notify_fail("�����ڳ���Ϸˮ��\n");

	if ( me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("��������æ���ء�\n");

	inv = all_inventory(me);	
	for (i=0; i<sizeof(inv); i++) {
		if ( (string)inv[i]->query("equipped")=="worn" ) 
			switch(inv[i]->query("armor_type")) {
				case "cloth":
				case "armor":
				case "suncoats":
					if ( inv[i]->query_weight() > 8000)
						return notify_fail("���ų��صļ�θ��ˮ�����������㰡����\n");
					else 
						me->receive_damage("jing", 10, me);
						return notify_fail(BLU"������ϴ����У�Ū�û����·�ʪ�����ģ��Ͻ����س��⡣���һ�����㲻��\n�ô���һ�����硣\n"NOR);
				case "boots":
					return notify_fail("����Ь��ˮ����\n");
				case "bandage":
					return notify_fail("�㻹�������أ�������ˮ���˿ڸ�Ⱦ����\n");
				default:
					break;
			}
	}
	inv = all_inventory(environment(me));
	for (i=0; i<sizeof(inv); i++) 
		if ( (string)inv[i]->query("race") == "����" && inv[i] != me && !me->is_spouse_of(inv[i]) )
			return notify_fail("��Ŀ��֮���ѹ�������ˮ���㲻�Ӻ����𣿣�\n");

        local = localtime(time()*60);
        t = local[2]*60 + local[1];

	message_vision(CYN"$N��ϴ�������ȥ��\n"NOR, me);
	me->set_temp("xixiang_swimming", 1);
	inv = all_inventory(me);
	flag = 0;
	for (i=0; i < sizeof(inv); i++) 
		if ( !inv[i]->query("armor_prop/armor") ) {
			destruct(inv[i]);
			flag += 1;
		}

	me->start_busy(10);
	if ( t > 1200 || t < 300 ) {
		write(HIB"��ʱҹ���˾����㾡����ڳ���Ϸˮ����������ĳ�ˮ���һ���ƣ�͡�\n"NOR);	
		call_out("out_of_pool", 20+random(12), me, 1);
	}
	else {
		write(HIB"��ˮ�������㾡����ڳ���Ϸˮ������ʱʱ�����Ƿ�����·�����ӡ�\n"NOR);
		call_out("out_of_pool", 20+random(12), me, 0);
	}
	if ( flag ) write(HIB"���������ϵ�Ǯ�ﶼ����ˮ�У���Ҳ�Ҳ����ˣ���\n"NOR);

	return 1;
}

void out_of_pool(object me, int recover)
{
	if ( !me->query_temp("xixiang_swimming") ) return;
	me->delete_temp("xixiang_swimming");

	if ( recover ) {
		tell_object(me, GRN"����һС��������������⣬ֻ��ƣ�;�ȥ�������ӡ�\n"NOR);
		if ( me->query("gender") == "Ů��" ) {
			me->add("jing", (me->query("eff_jing") - me->query("jing"))/2);
			me->add("qi", (me->query("eff_qi") - me->query("qi"))/2);
			me->add("jingli", (me->query("max_jingli") - me->query("jingli"))/2);
			me->add("neili", ((int)me->query("max_neili")-(int)me->query("neili"))/2);
			me->improve_skill("beauty", 15*me->query_per());
		}
		else {
			me->add("jing", ((int)me->query("eff_jing")-(int)me->query("jing"))/3);
			me->add("qi", ((int)me->query("eff_qi")-(int)me->query("qi"))/3);
			me->add("jingli", ((int)me->query("max_jingli")-(int)me->query("jingli"))/3);
			me->add("neili", ((int)me->query("max_neili")-(int)me->query("neili"))/3);
		}
		message("vision", "ֻ��"+me->name()+"��������ش�ϴ���������������\n",
			 environment(me), ({ me }) );
	}
	else {
		tell_object(me, GRN"����һС�����������ڳ��������ˣ����س��⡣\n"NOR);
		message("vision", "ֻ��"+me->name()+"��ϴ���������������\n",
                         environment(me), ({ me }) );
		me->improve_skill("force", random(me->query_con()/5));
		if (me->query("gender") == "Ů��")
			me->improve_skill("beauty", 5*me->query_per());
	}
	me->start_busy(1);
}
