//Cracked by Roath
// jiuyin_force_book.c �����澭�ڹ�ƪ
// by sdong 08/98

inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>

int do_read(string arg);

void create()
{
		  set_name(HIB"�����澭"NOR, ({ "jiuying zhenjing", "zhenjing" }));
		  set_weight(600);
		  if( clonep() )
					 set_default_object(__FILE__);
		  else {
					 set("unit", "��");
					 set("long", "����һ�����Ƶ���װ�飬���顶�����澭��ƪ֮�ڹ��ķ���������������ϳ˵��ڹ��ķ�����ϧȱ�˺ö�ҳ��\n");
					 set("value", 1000000);
					 set("material", "paper");
					 set("skill", ([
								"name": "force",        // name of the skill
								"exp_required": 1000000,  // minimum combat experience required
								"jing_cost":    100,     // jing cost every time study this
								"difficulty":   30,     // the base int to learn this skill
								"max_skill":    500      // the maximum level you can learn
					 ]) );
		  }
		  ::create();
}

void init()
{
		  add_action("do_read", "du");
		  add_action("do_read", "study");
}

int do_read(string arg)
{
	object me = this_player();

		if( me->query("9yin") != "granted" )
		{
			message_vision("$N������֭Ҳ���������Ȿ$n��\n",me,this_object());
			return 1;
		}
		else return "/cmds/skill/du.c"->main(me, arg);

}


