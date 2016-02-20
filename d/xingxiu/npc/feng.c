//Cracked by Roath
// npc: /d/xingxiu/npc/ke.c
// Jay 3/27/96

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
        set("long", "�����θߴ󣬸߱���Ŀ������ѩ�׶��룬����������\n"
		"������ʹ�����ųơ���������\n");
	set("nickname","�϶���");
        set("title", "����ɽׯ��");
        set("gender", "����");
        set("age", 65);

        set_skill("hand", 180);
	set_skill("shexing-diaoshou", 200);
	set_skill("strike", 180);
	set_skill("xingxiu-duzhang",180);
        set_skill("dodge", 150);
	set_skill("chanchubu", 150);
        set_skill("parry", 150);
        set_skill("force", 150);
	set_skill("hamagong", 150);
	set_skill("lingshe-zhang",200);
	set_skill("staff",200);
	set_skill("training",180);
	map_skill("hand","shexing-diaoshou");
	map_skill("strike","xingxiu-duzhang");
	map_skill("staff","lingshe-zhang");
        map_skill("dodge","chanchubu");
	map_skill("parry", "lingshe-zhang");
	map_skill("staff","lingshe-zhang");
	map_skill("force","hamagong");
	prepare_skill("hand","shexing-diaoshou");
	prepare_skill("strike","xingxiu-duzhang");

        set("str", 33);
        set("int", 28);
        set("con", 29);
        set("dex", 28);

        set("max_qi", 3000);
	set("qi",3000);
        set("max_jing", 800);
	set("jing",800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 300);
        set("combat_exp", 1500000);

        set("attitude", "peaceful");
        set("shen_type", -1);

        create_family("����ɽ", 1 , "ׯ��");
	setup();
        carry_object("/d/xingxiu/npc/obj/shezhang")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        mapping fam;
	string son;

        if( !mapp(fam = ob->query("family")) || fam["family_name"] != "����ɽ")
	{
		command ("say " + RANK_D->query_respect(ob) + 
			"��ȥ��ɽׯ��ʦ���˷��������´���Ӱɡ�");
		return;
	}
	if ((int)ob->query_skill("hamagong", 1) < 100) {
                command("say ���ǰ���ɽׯ�ľ������Ҵ��ĸ�󡹦��"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ���ڸ�󡹦�϶��µ㹦��");
                return;
        }
        if ((int)ob->query_skill("training", 1) < 100) {
                command("say ���ǰ���ɽׯ����ҪѵԦ���棬"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "��Ԧ�����������á�");
                return;
        }
	if (ob->query("gender")=="Ů��") son = "��Ů";
	else son = "����";
	command("�ҿ������ʴ�ӱ������������"+ son +"�������ϰ������常���͸���"
		"�ĸ�ͷ(ketou)��");
	ob->set_temp("ouyangfeng",1);
	add_action("do_ketou","ketou");
	return;
}

int ketou(string arg)
{
	object ob = this_player();
	if (!ob->query_temp("ouyangfeng")) return 0;
	message_vision(
                "$N˫ϥ�򵹣�����$n˵�������常���ϣ����ܺ���һ�ݣ���\n\n"
                "$n���˵������Ҳ�������$N�ӵ��Ϸ���\n\n",
                ob, this_object() );

	command("say ���ӣ���Ҫ��Ϊ�����⡣");
        command("recruit " + ob->query("id"));
	ob->set("title","����ɽׯ��ׯ��");
	return 1;
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
	if (me->query("family/family_name") != "����ɽ")
	me->apply_condition("snake_poison", 2 +
		me->query_condition("snake_poison"));
	return;
}
