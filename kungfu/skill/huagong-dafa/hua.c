//Cracked by Roath
// ��������
// wsky 05/03/2k

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("�����������ʹ�û�����ͨ��\n");

        if( (int)me->query("max_neili") < 2000  )
                return notify_fail("���������Ϊ������\n");

        if( (int)me->query_temp("hua") )
                return notify_fail("���Ѿ������û����󷨻�ס�����Ѩ��\n");

        if( (int)me->query_skill("huagong-dafa", 1) < 150)
                return notify_fail("��Ļ�������Ϊ������\n");

        if( (int)me->query("canhua") != 1)
                return notify_fail("��Ļ�������Ϊ������\n");


        skill = me->query_skill("huagong-dafa", 1);
 
        me->add("neili", -500);

        message_vision(HIB"$N��ɫ���䣬��ֻ�ֽ��沢����ǰ��Ǳ���ڹ����������󷨹�������ȫ��\n"NOR, me);

        me->add_temp("apply/parry",  skill/3);
        me->set_temp("hua", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill/10);

        if( me->is_fighting() ) me->start_busy(random(2)+1);

        return 1;
}

void remove_effect(object me, int skill)
{
        me->delete_temp("hua",1);
        me->delete_temp("apply/parry",  skill/2);                       
        message_vision(HIY"$N΢��ƣ����ֻ�ý�����������ջء�\n"NOR,me);
}

