//Cracked by Roath
// yingying.c ��ݺݺ

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��ݺݺ", ({ "cui yingying", "cui", "ying" }));
        set_color("$YEL$");
	set("long", "�����ü������������Ƕ��۾����ĵ�ֱ���Թ��˻��ǡ�\n");
	set("title", "����Ů��");
	set("gender", "Ů��");
	set("age", 17);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 20000);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"obj/necklace")->wear();
}
	
int accept_kill(object me)
{
        command("say ������������" + me->name() + "���" + RANK_D->query_rude(me) + "Ҫǿ���ң�\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

