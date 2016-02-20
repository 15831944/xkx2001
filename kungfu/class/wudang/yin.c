//Cracked by Roath
// /kungfu/class/wudang/yin.c ����ͤ
// xQin 14/08/99
// xQin 15/2/99
// xQin 04/01

inherit NPC;
inherit F_MASTER;
string ask_me(object me);

int auto_perform();

void create()
{
        set_name("����ͤ", ({ "yin liting", "yin" }));
        set("nickname", "�䵱����");
        set("long",
                "�����������������������ͤ��\n"
                "�����������ʮ���꣬���Ѿ�����糾֮ɫ������΢���߰ס�\n"
                "���䵱�����������������䵱������Ϊ��ͨ��\n");
        set("gender", "����");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 32);
        set("int", 38);
        set("con", 36);
        set("dex", 38);

        set("max_qi", 2600);
        set("max_jing", 2200);
        set("neili", 3200);
        set("max_neili", 3200);
        set("jiali", 100);
        set("combat_exp", 800000);
        set("shen", 80000);

        set_skill("force", 160);
        set_skill("taiji-shengong", 160);
        set_skill("dodge", 180);
        set_skill("tiyunzong", 180);
        set_skill("cuff", 120);
        set_skill("taiji-quan", 120);
        //set_skill("chang-quan", 120);
        set_skill("strike", 120);
        set_skill("mian-zhang",120);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        //set_skill("wudang-jian", 200);
//      set_skill("throwing", 100);
        set_skill("literate", 180);
        set_skill("taoism", 180);
       // set_skill("taiji-gong",140);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("strike", "mian-zhang");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");
        prepare_skill("strike", "mian-zhang");

        create_family("�䵱��", 2, "����");


       
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action("sword.shenmen") :),
        }) );


        set("inquiry", ([
                "���ͬ��" : (: ask_me :),
                "����ܽ" : "��������δ���ŵ����ӣ���Ȼ����������ͽ������",
                "����" : "����һ����Ҫ������ħ���������Լ���ܽ���졣����",
		"����ʮ����" : "����ʮ�����ˡ����� ����������ܽ��Ȼ����������ͽ������",

        ]));

	
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
        command("sigh");
        command("say ��Ȼ" + RANK_D->query_respect(ob) + "Ҳ��" +
                "�ұ����ˣ�������ܽȥ������������ͽ���������ҽ���"+
                "���Ҳ����Ե���Ҿʹ���һʽ�����ͬ�١���Ҳ����������"+
                "ʶһ����");

        ob->set("yinliting_teach",1);
}

string ask_me(object me)
{
        mapping fam; 
        me=this_player();
        
	if(me->query("family/family_name") != "�䵱��")
        {
        return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	}

	if(me->query_skill("taiji-shengong") < 60 )
	{
        command("say ���䵱�����ڼ��书���������ڹ��ķ���"); 
        return RANK_D->query_respect(me) + "�Ƿ�Ӧ����̫�����϶��µ㹦��";
	}

	if(me->query("shen") < 800000 )
	{
	command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
        return RANK_D->query_respect(me) + "��������" + "��������֮�£���һ�����㡣";
	}

	me->set("yinliting_teach", 1);
	command("sigh");
        return RANK_D->query_respect(me) + "Ҳ��" +
        "�ұ����ˣ�������ܽȥ������������ͽ���������ҽ���"+
        "���Ҳ����Ե���Ҿʹ���һʽ�����ͬ�١���Ҳ����������"+
        "ʶһ����";
	
}