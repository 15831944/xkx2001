//Cracked by Roath
inherit NPC;

void create()
{
        set_name("������", ({ "duan yanqing", "duan", "yanqing" }));
        set("nickname", "�����ӯ");
        set("long", 
"���������޳�������͹��������һ�ģ�����ȳ��˫�ȣ����Ÿ����ƹ��ȡ�\n");
        set("gender", "����");
        set("age", 55);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2000);
        set("max_jing",1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
        set("combat_exp", 1500000);
        set_temp("apply/attack",  120);
        set_temp("apply/defense", 120);

        set_skill("force", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("finger", 180);
        set_skill("kurong-changong", 180);
        set_skill("yiyang-zhi", 180);
        
        set_skill("strike", 180);
        set_skill("staff", 180);
        
        map_skill("dodge", "ding-dodge");
        map_skill("force", "kurong-changong");
        map_skill("finger", "yiyang-zhi");

        prepare_skill("finger", "yiyang-zhi");

        create_family("����μ�", 13, "����");

        setup();
        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}
void init()
{
        object ob;
//      ::init();
        if (interactive(ob = this_player()) &&
                (int)ob->query_condition("xakiller")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}

void attempt_apprentice(object me)
{

        if ((int)me->query("shen") > -100000){
                command("say ��������׵��ϵ��Ե�Ҳ�Ҷ���������?��");
                return;
        }
       if( me->query("combat_exp") < 100000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "
		�书��δ�������ң���������������ȥ�ɡ�");
                return;
        }

	if ((string)me->query("gender") !== "����") {
                command("say ��ֻ����ͽ��" + RANK_D->query_respect(ob) + 
"������Ͷ�����ɡ�");
                return;
        } 
if( me->query("PKS) < 50) {
command ("say " + RANK_D->query_respect(this_player()) + "
����ȥ�ɵ������׵������������ң���ʱ��һ�����㡣");
                return;
        }
    command("say �ðɣ��Ҿ��������ˡ�ϣ�����ܶ�ɱ�����������֣�Ϳ�����֡�");
        command("recruit " + me->query("id"));
       
 void init()
{
        object ob;

        ::init();
        if (interactive(me=this_player()) && 
me->query("family/master_id") == "duan yanqing"
        && me->query("shen") > -100000 ) {
                command("say " + RANK_D->query_rude(me) + 
"���Ҳ���ʦѵ����ȥΪ����������ô�ĵ��ӣ�" );
                command( "expell " + me->query("id"));
        }
}
}
