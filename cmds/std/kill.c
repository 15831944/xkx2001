//Cracked by Roath
// kill.c
//modified by arthurgu for surrender ,10/99

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj;
        string *killer, callname;
        int time;
        time = ((me->query("mud_age"))-(me->query("pktime")));
        
        if( environment(me)->query("no_fight") )
                return notify_fail("���ﲻ׼ս����\n");

        if( !arg )
                return notify_fail("����ɱ˭��\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");

        if(((string)SECURITY_D->get_status(me)=="(immortal)" )
         && ((string)SECURITY_D->get_status(obj)!="(immortal)" ))
                return notify_fail("�㲻��ɱ����ˣ�\n");

        if( me->query_temp("last_persuader") == obj->query("id") )
// no chinese input now, will change message
                return notify_fail("�㲻��ɱ����ˣ�\n");

      if( me->query("id") == obj->query_temp("surrender/ownder") )
                return notify_fail("��/���Ѿ�Ͷ����,�����ڲ���ɱ��\n");
            
      if( me->query_temp("surrender/ownder")!=0 )
                return notify_fail("���Ͷ�������ˣ��������Ÿɻ��£�\n");
                
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if( me->query("rided"))
                return notify_fail("��������ɱ������Ų�����ɡ�\n");

        if(obj==me)
                return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

        if( strsrch(file_name(environment(me)), "/d/xiakedao/") >= 0 && userp(obj))
                return notify_fail("��������������ڵ��Ϲ������ˣ�\n");

        if(userp(obj) && userp(me) && (me->query_condition("pker") > 240 
                                    || obj->query("mud_age") < 18000) )
                return notify_fail("��е�һ˿�ھΣ���ͻȻ����������\n");
                
/*        if(userp(obj) && userp(me) && time < 3600 && 
		obj->query("combat_exp") < me->query("combat_exp")/5 )
//		if(userp(obj) && userp(me))
                return notify_fail("���Ծ�ɱ��̫�أ�������������\n");
  */              
        callname = RANK_D->query_rude(obj);

        message_vision("\n$N����$n�ȵ�����" 
                + callname + "�����ղ������������һ��\n\n", me, obj);

        if( ! living(obj)
        && obj->query_temp("last_damage_from") != me) 
        me->set_temp("free_rider", 1);

        me->kill_ob(obj);
        
        if( !userp(obj) )
        {
                obj->accept_kill(me);
                if (!obj->is_grpfight()) 
                        obj->kill_ob(me);
        }
        else {
                if (!obj->is_killing(me->query("id"))) 
                        me->set_temp("pking/"+obj->query("id"), 1);
                obj->delete_temp("initiator");
                obj->fight_ob(me);
                obj->add_temp("initiate_pk", ({me->query("id")}));
                tell_object(obj, HIR "�����Ҫ��" + me->name() 
                        + "�����ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
        }

        return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : kill <����>
 
���ָ������������ʼ����һ�����������ͼɱ���Է���kill �� fight ����
��ͬ���˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ���� kill ֻ�赥��
��һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����ͨ�����
�Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��

�����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬���һ����Ҷ��ԣ����
��û�ж�һ������ʹ�ù� kill ָ��Ͳ��Ὣ�Է���Ĵ��˻�ɱ��( ʹ�÷�����
��)��

�������ָ��: fight

�й� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
