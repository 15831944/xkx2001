//Cracked by Roath
// shenggu.c Ī����
// xQin 6/2000

#include <ansi.h>
inherit	NPC;
inherit F_MASTER;

void init();
int accept_object(object who, object ob);

string ask_me();
string ask_me1();
string ask_me2();

void create()
{
	set_name("Ī����", ({ "mo shenggu", "mo", "shenggu" }));
	set("nickname",	"�䵱����");
	set("long",
		"�������������С�ĵ���Ī���ȡ�\n"
		"�����ױ������ϳɣ�Ƣ���ֺ�ֱˬ�����ÿ�����ΰ��������Ũ�ס�\n"
		"�书������ޡ������һ��\n");
	set("gender", "����");
	set("age", 35);
	set("attitude",	"peaceful");
	set("shen_type", 1);

	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 60);
	set("combat_exp", 700000);
	set("score", 700000);
	set("wudang/raozhi", 1);

	set_skill("force", 185);
	set_skill("taiji-shengong", 150);
	set_skill("dodge", 160);
	set_skill("tiyunzong",	160);
	set_skill("cuff", 150);
	set_skill("strike", 150);
	set_skill("mian-zhang",150);
	set_skill("parry", 150);
	set_skill("sword", 185);
	set_skill("taiji-jian", 170);
	set_skill("throwing", 150);
	set_skill("literate", 120);
	set_skill("taoism", 120);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
	map_skill("strike", "mian-zhang");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	prepare_skill("cuff", "chang-quan");
	prepare_skill("strike",	"mian-zhang");
	
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action("sword.raozhi") :),
	}) );

	create_family("�䵱��",	2, "����");

	        set("inquiry", ([
                "��ָ�ὣ" : (: ask_me :),
                "������" : (: ask_me1 :),
                "raozhi" : (: ask_me :),
                "qingshu" : (: ask_me1 :),
		"teach" : (: ask_me2 :),
		"ָ��" : (: ask_me2 :),
		               
        ]));

	set("chat_chance",6);
        set("chat_msg", ({
            "Ī����˵��: ��֪�������ϵ�����Ϊʲô���������һ���䵱������\n",
            "Ī����˵��: ��Ϊ�䵱����Ӧʱʱ������Ϊ�ȣ���Ҫ�мǰ���\n",
            "Ī����˵��: ��Ϊ����֮�������Լ��ú�������ɡ� \n", 	
	    "Ī����˵��: �����Ǹ�������֪������ȥ�ˣ��ϴ��ڶ����治Ӧ�������ӵ��� \n"	        
            "Ī����˵��: �´��ټ�������һ���������������ˡ� \n",	
        }));


	set("first_ask", 1);
	set("set_gocatch", 1);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/whiterobe")->wear();
}

	
void init()
{
	object ob;
	object me = this_player();
	
	::init();
	
	if(present("qingshu", environment(me))) {
        command("sigh qingshu");
        call_out("qingshustory", 1, ob);
	
}
	
	
	if( interactive(ob = this_player()) && ob->query("family/family_name") == "�䵱��" )
		call_out("greeting", 1, ob);
}


void greeting(object me)
{
	command("nod " + me->query("id"));
}

string ask_me()
{
        mapping fam; 
        object me, ob, *obs;
        me = this_player();

	
       		                
        if (me->query("can_fight", 1)) 
	   	{
		add_action("do_fight", "fight");
		command ("ok");
		me->delete("can_fight");
		me->set("fight_mo", 1);
		command("fight " + me->query("id"));
		return "��Ȼ�����ץ���˱�����ͽ�����ҿ�����Ե��������������������ְɡ�";
		}
        
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
                { 
               	command ("brother2");               	
               	return RANK_D->query_respect(this_player()) + 
                "����Ҫ�������䵱�ɣ�";
               	}	
		
        if (query("first_ask") < 1)
                {
                command ("smile");	
                return "����ָ�ὣ�������䵱�ɵľ���";
		}
        
  	add("first_ask", -1);
        me->set("know_raozhi", 1);
        command ("hehe");
                return "��·����ָ�ὣ��ȫ���Ի���������佣�У�ʹ������˸�޳����������Ե��ܡ�";

	
}



string ask_me1()
{
        mapping fam; 
        object me, ob, qingshu, *obs;
        me = this_player();
        
                      
        
         if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
               { 
               	command ("hmm");               	
               	return RANK_D->query_respect(this_player()) + 
                "�� ���������ʲô��ϵ��";
               	}	
        
        
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
               	{ 
               	command ("hmm");               	
               	return RANK_D->query_respect(this_player()) + 
                "�� �벻Ҫ�����Ǹ�������";
               	}	
		
        if (query("set_gocatch") < 1)
                {
                command ("hmm");	
                return "�Ҳ����������Ǹ�������";
		}
        
  	add("set_gocatch", -1);
        me->set("set_gocatch", 1);
        command ("sigh ");
        return "�ϴβ�С�ı��Ǹ����������ˣ�����ʦ�Ų��ҡ�ֻ��ϧ�Դ��ϴ��ڶ��ұ������ߺ�һֱ�Ҳ�������";

	
}


int do_fight(string arg)

{
  int i;
  object me, ob, *inv;  
        
  me = this_player();

  if ( !arg ) return 0;

  ob = present(arg, environment());
        
  if (!objectp(ob)) return 0;
        
  if (me->query("fight_mo", 1)) 
        
  
   
     {       
    	    tell_object(HIR "�����Ҫ��Ī���������ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
            message("vision",
   HIR  "�����Ҫ��Ī���������ಫ������Ҳ���������һ�� kill ָ�\n"
       "������Ī������ɱ��" + me->name() +"\n"
   NOR, environment(), this_object() );
                   fight_ob(this_player());
    
    
      add_action("do_halt", "halt");	
      add_action("do_brother2", "brother2");
      add_action("do_kill", "kill");
      me->delete("fight_mo");
      me->set("brother2_mo", 1);
      me->set("halt_mo", 1);
      
      return 1;
    }

}

int do_halt()
{
  object ob, obj=this_object();
  
  ob = this_player();
        
  
  if ( ob->query("halt_mo", 1) )
    {
      
      ob->delete("brother2_mo");
      ob->delete("halt_mo");
      command("sigh"); 
      command("halt");
      command("say ��Ȼ��ˣ����߰ɡ� ��û��ʲô�ý���ġ�");

      

 
  return 1;
}	
}


int do_kill(string arg)

{
  int i;
  object me, ob, *inv;  
        
  me = this_player();

  if ( !arg ) return 0;

  ob = present(arg, environment());
        
  if (!objectp(ob)) return 0;
        
        
  if ((string)(me->query("family/family_name")) == "�䵱��" 
      && ob->query("id") == "mo shenggu" )
    {
      message_vision("$N��ɱ��$n��\n"
                     "$n������$N�������ұ�ͬ�ţ�ȴΪ�����຦���ң�\n"
                     "$n������$N�����������ѧ������ָ�ὣ����\n"
                     "$n��$N�ܲ����⣡\n" , me,ob);
      command ("sigh");
      command ("disapp");
      
      ob->delete("brother2_mo");
      ob->delete("halt_mo");
      me->delete("can_fight");       
      me->add("wudang/offerring", -20);
      return 0;    

}
}

int do_brother2(string arg)

{
  int i;
  object me, ob, *inv;  
        
  me = this_player();

  if ( !arg ) return 0;

  ob = present(arg, environment());
        
  if (!objectp(ob)) return 0;
        
   if (me->query("brother2_mo", 1)) 
        
    {
      ob->delete("brother2_mo");
      ob->delete("halt_mo");
      me->delete("can_fight");
      me->set("can_teach", 1);   
      
      
      command ("say ��Ϊ�䵱���ӣ���������Ϊ�ȣ������������������ղ�����");
      command ("say ���ѵ����Ĵ����ʵ��������ˣ�ϣ�������Ϊ֮�����䵱������");
      command ("halt");
      command ("touch");
      command ("thumb");
      
      return 0;	
}
}
int accept_object(object who, object ob)
{
	object obn;

	
	if ( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, who) ) return notify_fail("��û�����������");
	if (who->query("know_raozhi") < 1) 
	return notify_fail("����ô������Ū�������ˣ�");
	if (who->query("set_gocatch") < 1) 
	return notify_fail("�����ʲô��");
	if (  (string)ob->query("name") == "qingshu"
		|| (string)ob->query("name") == "������"  ) 
	{
		if ( (string)ob->query("name") == "������" )
	{		
	who->delete("set_gocatch");
        who->add("can_fight", 1);
        who->add("wudang/offerring", 10);
        command	("thumb");
	command("touch " + (string)who->query("id")); 
        ob->move(this_object());
        if ( ob) destruct(ob);
	command("say" + RANK_D->query_respect(who)
	       	+ "лл�����ץ���������ͽ�� \n");
		}
	return 1;
	}
        command("? " + who->query("id"));
        
        
        return 0;
}



string ask_me2()
{
        mapping fam; 
        object me, ob, qingshu, *obs;
        me = this_player();
        
                      
        
         
        
        
        if ((int)me->query("can_teach", 1) < 1)
		{
		command ("hmm");
		return "�������ʲô��";
		}
		
	if ((int)me->query_skill("sword", 1) < 180)	
                {
                me->delete("can_teach");
                command ("hmm");	
                return "��Ľ�������̫ǳ��������ѧ����ָ�ὣ��";
		}
	
	if ((int)me->query_skill("force", 1) < 180)	
                {
                me->delete("can_teach");
                command ("hmm");	
                return "����ڹ����̫ǳ��������ѧ����ָ�ὣ��";
		}
        
  	
  	
  		me->set("wudang/raozhi", 1); 
      		me->add("wudang/offerring", 10);        
       		me->delete("can_teach");
      		command ("ok");
       		command ("say" + "���֪��Ʒ��������ģ�����Ҫѧ�ҾͰѡ���ָ�ὣ����������ɣ�\n");
       		message("vision", HIW  "��ϲ��ѧ���ˡ���ָ�ὣ����\n" NOR, me,ob);
         	return 0;         
  	
	
}

