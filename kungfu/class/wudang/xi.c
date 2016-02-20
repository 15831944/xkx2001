//Cracked by Roath
// xi.c ����Ϫ

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����Ϫ", ({ "zhang songxi", "zhang" }));
        set("nickname", "�䵱����");
        set("long", 
                "��������������ĵ�������Ϫ��\n"
                "��������ʮ�꣬��Ķ�С����������Ӣ����\n"
                "Ϊ�˾����ܸɣ������Ƕ�ı���ơ�\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 36);
        set("int", 44);
        set("con", 37);
        set("dex", 36);

        set("max_qi", 3000);
        set("max_jing", 2600);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 110);
        set("combat_exp", 900000);
        set("score", 50000);

        set_skill("force", 180);
        set_skill("taiji-shengong", 180);
        set_skill("dodge", 170);
        set_skill("tiyunzong", 170);
        set_skill("cuff", 160);
        set_skill("taiji-quan", 160);
        set_skill("strike", 170);
        set_skill("mian-zhang",170);
        set_skill("parry", 180);
        set_skill("sword", 190);
        set_skill("taiji-jian",190);
        set_skill("literate", 180);
        set_skill("taoism", 180);
        //set_skill("taiji-gong",160);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("strike", "mian-zhang");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");
	prepare_skill("strike", "mian-zhang");
	
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

        if ((int)ob->query_skill("wudang-jiuyang", 1) < 60) {
                command("say ���䵱�����ڼ��书���������ڹ��ķ���");
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�����䵱�������϶��µ㹦��");
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

