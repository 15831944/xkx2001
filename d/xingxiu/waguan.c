//Cracked by Roath
//10/8/00

inherit ITEM;
#include <ansi.h>

void setup()
{}


void create()
{
        set_name("�߹�", ({"wa guan", "wa", "guan"}));
        set_weight(15000);
        set_max_encumbrance(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "һֻ�ʵؾ�ϸ���߹ޡ�\n");
  		set("no_drop", 1);
        	set("no_get", 1);
	        set("no_steal", 1);
		set("no_sell", 1);
        }

//        ::create();
}
int is_container() { return 1; }

void init()
{
   add_action("do_hold", "kou");                       
   add_action("do_xiulian", "xiulian");	
}

int do_hold(string arg)
{
        string me, what;
        object ob, obj=this_object();

        if( !arg || sscanf(arg, "%s", what)!=1 )
                return notify_fail("�����ʽ: kou <��Ʒ> ��\n");

        ob = present(what, environment(this_player()));
        if( !ob ) return notify_fail("����û��" + what + "����������\n");

	if (ob->query("id")!="du chong") return notify_fail("�ⶫ����ò�Ҫץ��\n");

        if (this_player()->is_busy()) return notify_fail("����æ���ء�\n");

	else {
          	if(random(this_player()->query_skill("poison",1))*5 > (this_player()->query_skill("force")))
                        {    
                        message_vision("$N�������е��߹��͵ؽ������ס��Ȼ��С������ؽ��߹޷�������ס��\n",this_player());

                        this_player()->add("neili",-50);
			set("bug_hold",1);
			set("long", "һֻ�ʵؾ�ϸ���߹ޡ�\n����ʢ��һֻ���档\n");
			this_player()->set_temp("bug_hold",1);		
                        destruct(ob);
                        }
                else message_vision("$N�͵ĳ������߹޿���"+ob->query("name")+",��"+ob->query("name")+"����������ˡ�\n",this_player());
 		
                this_player()->start_busy(random(1)+1);               
                return 1;
        }
}

int do_xiulian()
{
        if (query("bug_hold")!=1) return notify_fail("û�ж��棬����Ҫ�ÿ���������\n");
	message_vision(HIR"$N����������Ȼ������۾�����ָ�����߹ޡ�\n"NOR, this_player());
        message_vision(HIR"��������ҧס$N��������Ѫ����\n"NOR, this_player());
	call_out("do_xiulian2", 8, this_player());
	this_player()->start_busy(10);
	return 1;
}

void do_xiulian2(object me){
	object dan;
	dan=new("/d/xingxiu/obj/dudan");
	dan->set("player",this_player()->query("id"));
	message_vision(HIG"���潫Ѫ���꣬���Ӹ߸�����ž��һ������޵ף������˼��£����ˡ�\n"NOR, this_player());
	message_vision("$N���������ó��߹ޣ���������ʿ����ó�һ������Ѫ�ĵ�������\n"NOR, this_player());
	tell_object(this_player(),"���ж��ˣ�\n");
        this_player()->apply_condition("insect_poison", this_player()->query("poison"));
        this_player()->improve_skill("poison", 200);
	this_player()->set_temp("found",1);
	dan->move(this_player());
}

