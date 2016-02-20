//Cracked by Roath
// yu.c ������

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "yu lianzhou", "yu" }));
	set("nickname", "�䵱����");
	set("long", 
		"������������Ķ����������ۡ�\n"
		"��������ʮ�꣬��Ŀ��࣬�������ء�\n"
		"�����䵱�����������ڶ�������ȴ�����\n");
	set("gender", "����");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1200);
	set("max_jing", 1200);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 800000);
	set("shen", 80000);

	set_skill("force", 120);
	set_skill("taiji-shengong", 110);
	set_skill("dodge", 130);
	set_skill("tiyunzong", 130);
	set_skill("cuff", 110);
	set_skill("taiji-quan", 110);
	set_skill("parry", 130);
	set_skill("sword", 130);
	set_skill("taiji-jian", 130);
//	set_skill("taoism", 80);
//	set_skill("literate", 50);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	prepare_skill("cuff", "taiji-quan");

	create_family("�䵱��", 2, "����");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
	mapping fam;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "�䵱��" )
	{
                command ("say " + RANK_D->query_respect(this_player())
                        + "�����������ˣ�ϰ�仹���ȴӸ�λ������ɣ�");
		return;
	}

	if ((int)ob->query_skill("taiji-shengong", 1) < 60) {
		command("say ���䵱�����ڼ��书���������ڹ��ķ���"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ����̫�����϶��µ㹦��");
		return;
	}

	if ((int)ob->query("shen") < 80000) {
		command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
		command("say " + RANK_D->query_respect(ob) + "��������" +
			"��������֮�£���һ�����㡣");
		return;
	}
	command("say �ðɣ���Ȼ" + RANK_D->query_respect(ob) + "Ҳ��" +
		"�ұ����ˣ������������ɡ�");
	command("recruit " + ob->query("id"));
}


// End of file 
