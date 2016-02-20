//Cracked by Roath
// song.c ��Զ��

inherit NPC;
inherit F_MASTER;

string ask_me();

int auto_perform();

void create()
{
        set_name("��Զ��", ({ "song yuanqiao", "song" }));
        set("nickname", "�䵱����");
        set("long", 
                "������������Ĵ���ӡ��䵱����֮�׵���Զ�š�\n"
                "ֻ������һ���ɸɾ����Ļ�ɫ���ۡ�����ȥ�������ʮ���ޱ�΢�����ף�\n"
                "���糤�봹�أ�������⣬��������嵭��ͣ���ò�������ţ����ȴ����\n"
                "���֣��������귢����\n" );
        set("gender", "����");
        set("age", 55);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 42);
        set("int", 40);
        set("con", 42);
        set("dex", 40);

        set("max_qi", 3500);
        set("max_jing", 3000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 120);
        set("combat_exp", 1100000);
        set("score", 60000);

        set_skill("force", 220);
        set_skill("taiji-shengong", 220);
        set_skill("dodge", 200);
        set_skill("tiyunzong", 200);
        set_skill("cuff", 220);
        set_skill("taiji-quan", 220);
        set_skill("strike", 180);
        set_skill("mian-zhang",180);
        set_skill("parry", 200);
        set_skill("sword", 160);
        set_skill("taiji-jian", 160);
        set_skill("literate", 200);
        set_skill("taoism", 200);
        //set_skill("taiji-gong",200);


        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("strike", "mian-zhang");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");
	prepare_skill("strike", "mian-zhang");
        create_family("�䵱��", 2, "����");

        set("inquiry", ([
                "�ؼ�" : (: ask_me :),
        ]));

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        set("book_count", 1);

        setup();
//      carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();

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
                        "�Ƿ�Ӧ�����䵱�������϶��µ㹦��");
                return;
        }

        if ((int)ob->query("shen") < 35000) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ�������������ˡ�");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        mapping fam; 
        object ob, *obs;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";

        if (query("book_count") < 1)
                return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";

        obs = filter_array(children(__DIR__"force_book.c"), (: clonep :));
        if (sizeof(obs) > 2)
                return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";

        ob=new(__DIR__"force_book");
        ob->move(this_player());
        add("book_count", -1);
        command ("rumor "+this_player()->query("name")+"Ū����һ��̫��ʮ��ʽ��");
        return "�ðɣ��Ȿ��̫��ʮ��ʽ�����û�ȥ�ú����С�";
}

#include "/kungfu/class/wudang/auto_perform.h"
