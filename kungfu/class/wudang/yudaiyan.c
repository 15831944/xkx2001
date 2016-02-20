//Cracked by Roath
// yudaiyan.c �����
// xQin 12/00
// xQin 04/01

inherit NPC;
inherit F_MASTER;
string ask_drug1();
string ask_drug2();
string ask_drug3();
string ask_drug4();

void create()
{
        set_name("�����", ({ "yu daiyan", "yu" }));
        set("nickname", "�䵱����");
        set("long", "�����䵱�����е������������ƹܵ�ҩ����\n"
        	    "ֻ������Ŀ�㲣�����֧���Ź����ƺ�ʮ�ֳ�����\n"
        	    "��˵����ǰ�򱻴����Դ������ָ������֫����������Ժ�����������Ƶ����޷�Ȭ����\n");
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 5);
        set("int", 38);
        set("con", 10);
        set("dex", 20);

        set("max_qi", 500);
        set("max_jing", 800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 0);
        set("combat_exp", 1050000);
        set("shen", 80000);

        set_skill("force", 120);
        set_skill("taiji-shengong", 120);
        set_skill("dodge", 100);
        set_skill("tiyun-zong", 100);
        set_skill("strike", 90);
        set_skill("mian-zhang",90);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("taiji-jian", 100);
        set_skill("literate", 150);
        set_skill("taoism", 150);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("strike", "mian-zhang");
        map_skill("sword", "taiji-jian");

        prepare_skill("strike", "mian-zhang");

        create_family("�䵱��", 2, "����");
	set("inquiry", ([
	"��ҩ��" : "���ﻹû����ȫ���ţ������ĵȴ���\n",
	"���Ľⶾ��" : (:ask_drug1:),
	"���Ʊ�����" : (:ask_drug2:),
	"�������ĵ�" : (:ask_drug3:),
	"�׻�������" : (:ask_drug4:),
	
	]));
	
	set("drug1_count", 5);
	set("drug2_count", 5);
	set("drug3_count", 5);
	set("drug4_count", 3);
	
        setup();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}

string ask_drug1()
{ 
	mapping fam; 
	object me, ob,*obs;
	me=this_player();
	ob=this_object();
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
        return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
        
        if (me->query_temp("obtained_drug1"))
        {
      	command("hmm "+me->query("id"));
        return "���Ľⶾ�������Ѿ�����������";
	}
	
	obs = filter_array(children("/clone/drug/tianxin.c"), (: clonep :));
        if (sizeof(obs) > 5)
                return "�������ˣ����Ľⶾ�����Ѿ�������ͬ�������ˣ���Ҫ�������ơ�";

	if (query("drug1_count") < 1)
        return "�������ˣ����Ľⶾ�����Ѿ�������ͬ�������ˣ���Ҫ�������ơ�";
        
	ob=new("/clone/drug/tianxin");
	ob->move(me);
	add("drug1_count", -1);
	me->set_temp("obtained_drug1", 1);
	message_vision("�����ת�������ң��ڼ�����������һ��С��ƿ�������浹��һ��ҩ�������$N��\n",me);
	return "�ðɣ�������һ�����Ľⶾ�����м�Ҫ���á�";
}
	
string ask_drug2()
{ 
	mapping fam; 
	object me, ob,*obs;
	me=this_player();
	ob=this_object();
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
        return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
        
        if (me->query_temp("obtained_drug2"))
        {
      	command("hmm "+me->query("id"));
        return "���Ʊ����費���Ѿ�����������";
	}
	
	obs = filter_array(children("/clone/drug/sanhuang-wan.c"), (: clonep :));
        if (sizeof(obs) > 5)
                return "�������ˣ����Ʊ����趼�Ѿ�������ͬ�������ˣ���Ҫ�������ơ�";

	if (query("drug2_count") < 1)
        return "�������ˣ����Ʊ����趼�Ѿ�������ͬ�������ˣ���Ҫ�������ơ�";
        
	ob=new("/clone/drug/sanhuang-wan");
	ob->move(me);
	add("drug2_count", -1);
	me->set_temp("obtained_drug2", 1);
	message_vision("�����ת�������ң��ڼ�����������һ��С��ƿ�������浹��һ��ҩ�������$N��\n",me);
	return "�ðɣ�������һ�����Ʊ����裬�м�Ҫ���á�";
}

string ask_drug3()
{ 
	mapping fam; 
	object me, ob,*obs;
	me=this_player();
	ob=this_object();
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
        return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
        
        if (me->query_temp("obtained_drug3"))
        {
      	command("hmm "+me->query("id"));
        return "�������ĵ������Ѿ�����������";
	}
	
	obs = filter_array(children("/clone/drug/huxin"), (: clonep :));
        if (sizeof(obs) > 5)
                return "�������ˣ��������ĵ����Ѿ�������ͬ�������ˣ���Ҫ�������ơ�";

	if (query("drug3_count") < 1)
        return "�������ˣ��������ĵ����Ѿ�������ͬ�������ˣ���Ҫ�������ơ�";
        
	ob=new("/clone/drug/huxin");
	ob->move(me);
	add("drug3_count", -1);
	me->set_temp("obtained_drug3", 1);
	message_vision("�����ת�������ң��ڼ�����������һ��С��ƿ�������浹��һ��ҩ�������$N��\n",me);
	return "�ðɣ�������һ���������ĵ����м�Ҫ���á�";
}

string ask_drug4()
{ 
	mapping fam; 
	object me, ob,*obs;
	me=this_player();
	ob=this_object();
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
        return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
        
        if (me->query_temp("obtained_drug2"))
        {
      	command("hmm "+me->query("id"));
        return "�׻������費���Ѿ�����������";
	}
	
	obs = filter_array(children("/clone/drug/baihu.c"), (: clonep :));
        if (sizeof(obs) > 5)
                return "�������ˣ��׻������趼�Ѿ�������ͬ�������ˣ���Ҫ�������ơ�";

	if (query("drug2_count") < 1)
        return "�������ˣ��׻������趼�Ѿ�������ͬ�������ˣ���Ҫ�������ơ�";
        
        if (me->query("combat_exp") < 50000 )
        {
        command("look "+me->query("id"));
        return "�׻����������ü�Ϊ���ף�����Ŀǰ�Ĺ���Ӧ�ò�����Ҫ�ģ��Ժ���˵�ɡ�";
        }
	ob=new("/clone/drug/baihu");
	ob->move(me);
	add("drug2_count", -1);
	me->set_temp("obtained_drug2", 1);
	message_vision("�����ת�������ң��ڼ�����������һ��С��ƿ�������浹��һ��ҩ�������$N��\n",me);
	return "�ðɣ�������һ�Ű׻������裬�����ò����м�Ҫ���á�";
}
// End of file 
