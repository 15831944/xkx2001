//Cracked by Roath
// Based on Jay 10/7/96
// ���͵�������ׯ�Ů
inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
          ��������̸�����ɽ�޲���ɫ��ׯ������ŷ�����������
    �е�һ���֡�ׯ���ĸ�󡹦�������֣������������ˣ���������
    �Ķ������յĶ��������޶��������������湦��ׯ����̣�Ҫ
    �ǵ������ⱻ�ۣ�����Ϊ���ͷ��",
});
int ask_menpai(string* message);

void create()
{
	set_name("����", ({ "diaochan" }));
	set("long", "һ����ʮ�������װŮ�ӣ���ò���㣬��ü���۽�͸��һ��а����ȴƫƫҪ�ùŴ���Ů�����֡�\n");
	set("gender", "Ů��");
	set("age", 22);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 100);

	set("attitude", "peaceful");
	set("shen_type", -1);

	create_family("����ɽ", 4 , "����");
	set("inquiry", ([
			"����ɽ"   :  (: ask_menpai, menpai:),
		]));

	setup();
        carry_object("/d/xingxiu/obj/wcloth")->wear();

}
void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	if (me->query_temp(this_object()->query("id")) == 0 )
	{	command("seduce " + me->query("id"));
		command("say ��λ" + RANK_D->query_respect(me) + "�����ǰ���ɽׯ�ɣ�����ׯ����������������ŷ\n"+
	     "���档����ʲ���������Ҿͺ�����"+HBRED+HIW"(ask diaochan about ����ɽ) (help baituo)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
