//Cracked by Roath
// xiaoyuan.c ��ɽСԺ
// by Xiang
// Modified by xQin 11/00

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "��ɽСԺ");
	set("long", @LONG
���Ǻ�ɽ��һ��СԺ�����ü�򵥵�������һ����һ����һ�Ρ�һ����
����Ҳû�б��ʲ��Ƚ�����עĿ����ǽ�Ϲ���һ�ѽ�����������䵱��
ɽ��ʦ��������������ڡ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"hs_xiaolu",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/zhang" : 1 ]));
	create_door("north", "����", "south", DOOR_CLOSED);
	set("cost", 1);
	setup();
}
void init()
{
        add_action("do_kill","kill");
}
int do_kill(string arg)
{
        object ob, ob1, me = this_player();

        if ( !arg || arg == "" ) return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;
        if ( !ob1=present("zhang sanfeng", environment(me)) ) return 0;
	if ( ob1 == ob ) return 0;
        if ( ob->query("family/family_name") == "�䵱��" ) {
                message_vision("$Nһ����Ц���󵨿�ͽ����Ҳ̫С����ͷ�����˰ɣ�\n ", ob1);
                ob1->kill_ob(me);
	}
	return 0;
}
