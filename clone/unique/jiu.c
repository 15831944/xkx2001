//Cracked by Roath
// xuanbing_bihuo_jiu.c  �����̻��
// xQin 8/00

inherit F_UNIQUE;
inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_drink", "drink");
        add_action("do_drink", "he");
}
void create()
{
        set_name(HIC"��"HIW"��"HIG"��"HIR"��"YEL"��" NOR, ({"xuanbing_bihuo jiu", "jiu"}));
        set("unit", "ƿ");
        set("long", 
        	"��ƿ���ǽ�����˵�е������̻�ƣ� ����ʮ�����ҩ�Ķ���ɡ�\n"
        	"�˾ƾ�˵������������֮�����Ⱥ���ɹ��������\n");
        set("no_drop","��ô����Ķ�����ô�����뿪�㣿��\n");
        set("no_get", "�������������뿪�Ƕ���\n");
        set("value", 10000000);
        setup();
}
int do_drink(string arg)
{
	object me, add;
	me=this_player();

	
        if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
        
        if(arg=="jiu") {
        if (me->query("wine/drank"))
        {
        write(HIW"�˾��˴�֮ҩ��һ���кȵ�һ��������Ե�����ܶ�ȷ�����Ԫ����"NOR);
        return 1;
        }
        if (me->query_condition("bonze_drug") > 0)
        {
	me->add("max_jing",-10-random(20));
        me->add("eff_jing",-10-random(20));
        me->add("max_qi",-10-random(20));
        me->add("eff_qi",-10-random(20));
        me->add("max_jingli",-10-random(20));
        me->add("eff_jingli",-10-random(20));
        me->add("max_neili",-10-random(20));
        me->add("eff_neili",-10-random(20));
        message_vision(HIR"$N��ʣ�µ������̻��һ��������ֻ�������������Ĵ���ɢ��������ȡ�\n"
        	 	  "�������ǰ����ҩ��δɢ�������������̻�Ƶ�ҩ����ˣ���������\n" NOR, me );
        me->apply_condition("bonze_drug", me->query_condition("bonze_drug")+70);
        me->set("drunk_apply", 20);
        me->unconcious();
        destruct(this_object());
        return 1;
	}
	else {
             me->add("max_jing",10+random(20));
             me->add("eff_jing",10+random(20));
             me->add("max_qi",10+random(20));
             me->add("eff_qi",10+random(20));
             me->add("max_jingli",10+random(20));
             me->add("eff_jingli",10+random(20));
             me->add("max_neili",10+random(20));
             me->add("eff_neili",10+random(20));
             message_vision(HIG"$N��ʣ�µ������̻��һ��������ֻ��һ�����������ķΣ���ʱ��̨һƬ������������ˬ��\n" NOR, me );
             me->apply_condition("bonze_drug", 100);
             me->set("drunk_apply", 20);
             me->set("wine/drank", 1);
             destruct(this_object());
        }
        return 1;
		}
}