//Cracked by Roath
// san.c һ����ɢ
/*
�����ʲ�������һ�ƣ�ʵ�Ǳ�������֮���ۣ�������һ����ɢ����
��ν����ɢ������ָ����ʯ�ϣ�ʯм�ġ�ɢ���������������
�ǡ�ɢ������·�Ʒ���ֻ��ôһ�У�ֻ������̫���ۻ룬�ٵ�ʱ
�ò���ʹ�ڶ��У����˱��ѱ���������һ���������ɽ�������
����Ϊ������Ҫ����л�ʽ���������֮���ܡ�
*/

inherit F_SSERVER;

int perform(object me, object target)
{
        int org_enfor, enfor;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("һ����ɢֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("weapon") )
                return notify_fail("��ֻ���ڿ���ʱʹ��һ����ɢ��\n");

        if( me->query_skill_mapped("force") != "hunyuan-yiqi" )
                return notify_fail("�����õĲ��ǻ�Ԫһ�������޷�ʩչһ����ɢ��\n");

        if( me->query_skill("hunyuan-yiqi", 1) < 180)
                return notify_fail("��Ļ�Ԫһ�������δ�����޷�ʩչһ����ɢ��\n");

        if( me->query_skill("banruo-zhang", 1) < 180 )
                return notify_fail("��İ����ƻ��δ�����޷�ʩչһ����ɢ��\n");

        if( me->query_skill("buddhism", 1) < 180 )
                return notify_fail("��ķ�ѧ��Ϊ�������޷�ʩչһ����ɢ��\n");

        if( me->query("max_neili") <= 1000 )
                return notify_fail("���������Ϊ���㣬���������˷����޷�ʩչһ����ɢ��\n");

        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("�������������\n");

        if( (int)me->query("jingli") < 500  )
                return notify_fail("��ľ���������\n");
        
        org_enfor = me->query("jiali");

        // I tried the original code with no restriction, a 4Kneili player
        // can make 15K damage in this 1 hit.  With the limit, a 4K
        // neili player can still make 4K damage sometimes. -Chu

	enfor = me->query("max_neili")/10;
	enfor = org_enfor + enfor/2;
	enfor = enfor/2+random(enfor);

        me->set("jiali", enfor);

	if( wizardp(me) ) tell_object(me, "enforce : " + enfor);

	me->set_temp("sl_perform/san", 1);
	if( me->query_skill_prepared("finger") == "yizhi-chan" )
	{
		me->set_temp("restore_yzc", 1);
		me->prepare_skill("finger");
	}
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->delete_temp("sl_perform/san");
	if( me->query_temp("restore_yzc") )
	{
		me->prepare_skill("finger", "yizhi-chan");
		me->delete_temp("restore_yzc");
	}

        me->add("neili",-(500+enfor*2));
        me->add("jingli",-(300+enfor));
	if( me->query("neili") < 0 ) me->set("neili", 0);
	if( me->query("jingli") <= 0 ) me->set("jingli", 1);
        me->set("jiali", org_enfor);
        me->start_busy(4+random(3));
        return 1;
}
