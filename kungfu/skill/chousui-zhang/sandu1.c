//Cracked by Roath
// /kungfu/skill/chousui-zhang/sandu  pfm ɢ��
// Summer, 12/28/96.
// modified by sdong 7/16/1999. Let ppl can sandu on NPC with exp 1/3 higher than self
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object room, mengzhu;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�㲻��ս���С�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

	//if( !userp(target) )
	//	return notify_fail("��ֻ�����������ɢ����\n");

		  if(!( room = find_object("/d/taishan/fengchan")) )
		  room = load_object("/d/taishan/fengchan");

		  if( target->query("id") == room->query("winner") )
		return notify_fail("�󵨣����Ҷ�����ɢ��������ȫ����Ϊ����\n");

	if( (int)me->query_skill("chousui-zhang", 1) < 30 )
		return notify_fail("��ĳ�������Ϊ������\n");

	if( (int)me->query_skill("poison", 1) < 50 )
		return notify_fail("��Ļ���������Ϊ������\n");

	if ( me->query_skill_mapped("force") != "huagong-dafa")
					 return notify_fail("��û���˻����󷨣�\n");

	if( me->query("neili") <= 100 )
					 return notify_fail("�������������\n");

	if( target->query_condition("poisoned") > 0 || ( me->query("last_sandu") == target->query("id") && userp(target) ) )
		return notify_fail("���������о綾���й������ã��ڴ�������ɢ����ʹ�㷴���亦��\n");

	message_vision(MAG "$N�����ƻ���̧��������ɫ������ϣ�ð��һ���ƺ��������Ŵ��һ����������$n���Ĺ�ȥ��\n\n" NOR, me,target);
	me->add("neili", -150);
	if( !userp(target) ) target->kill_ob(me);

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")*6/11){
	if( ( (int)target->query("combat_exp") > me->query("combat_exp")/2 && userp(target) ) ||
		 (	(int)target->query("combat_exp") > me->query("combat_exp")/3*4 && !userp(target) )
		){
	if( me->query_skill("poison", 1) < target->query_skill("poison", 1) * 2){
	tell_object(me, BLU "��һ������" +target->query("name") +"�ؿڣ����ϴ������ھ۶����ͣ��㲻�ܰѶ�ɢ���������亦��\n"NOR);
	tell_object(target, BLU "��ֻ��һ�ɺ���Ϯ�棬�ƺ�һ�����ؿ����ơ�\n" NOR);
		me->add("max_neili", - 1);
		me->apply_condition("xx_poison", 50+me->query_condition("xx_poison"));
		target->add("qi", - me->query_skill("chousui-zhang"));
		target->apply_condition("xx_poison", 10+target->query_condition("xx_poison"));
	return 1;
	}
	else {
	tell_object(me, BLU "��һ������" +target->query("name") +"�ؿڣ������������ֿ���˳�ư������������ƽ�" +target->query("name") +"���ڡ�\n"NOR);
	tell_object(target, BLU "��ֻ��һ�ɺ���Ϯ�棬�н��������ֿ�������" +me->name() +"���綾��һ��һ���������ؿ��ϡ�\n"NOR);
		me->add("max_neili", - 1 - (int)me->query_skill("huagong-dafa", 1)/15);
		if (me->query_skill("poison", 1) < 101)
		me->set("body_poison",me->query_skill("poison", 1)/10+1);
		if (me->query_skill("poison", 1) > 100)
		me->set("body_poison", me->query_skill("poison", 1));

					 target->add("qi",-(random((int)me->query_skill("chousui-zhang"))));
		target->receive_wound("jing", (int)me->query_skill("chousui-zhang"));
		target->apply_condition("xx_poison", me->query_skill("poison", 1)*2);
		target->apply_condition("poisoned", me->query_skill("poison", 1)*3);

		if (userp(target))
		me->add("combat_exp", me->query_skill("poison", 1) * 5);
		else me->add("combat_exp", me->query_skill("poison", 1) );

		me->set("last_sandu", target->query("id"));
	log_file("POISON", sprintf("%s(%s) ɢ�� on %s.\n",
						me->query("name"), getuid(me), target->query("name")));

	return 1;
				}
	}
	tell_object(me, BLU "��һ������" +target->query("name") +"�ؿڣ�����" +target->query("name") +"����̫�����㷴���ܰѶ����Ƴ�ȥ����������\n"NOR);
	tell_object(target, BLU "��ֻ��һ�ɺ���Ϯ�棬�ƺ�һ�����ؿ����ơ�\n" NOR);
					 target->add("qi",-(random((int)me->query_skill("chousui-zhang"))));
		target->receive_wound("jing", (int)me->query_skill("chousui-zhang"));
		target->apply_condition("xx_poison", 5 + target->query_condition("xx_poison"));
		target->start_busy(1+random(3));
	}
	else
	{
	message_vision(HIY "$p�Ͻ�����Ծ�����ɣ��㿪$P�Ĺ�����\n" NOR, me, target);
	}


	me->start_busy(1+random(5));
	return 1;
}
