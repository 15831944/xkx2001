//Cracked by Roath
// room: /d/xingxiu/btshan
// Jay 3/27/96

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ǰ���ɽׯ�ĳ�����������һ�������һ��ˮ�ף�����ɽׯ��
�����ǿ����������ˮ(drink)�������Ů��æ��������
LONG
        );
        set("exits", ([ 
	    "north" : __DIR__"btyard",
        ]));
        set("resource/water", 1);


        set("objects", ([ 
            CLASS_D("baituo")+"/binu" : 2,
	    __DIR__"obj/shegeng" : 2,
	    __DIR__"npc/snake" : 1,
         ]) );
//        replace_program(ROOM);
	set("cost", 0);
        setup();
}

void init()
{
        add_action("do_drink", "drink");
}
int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"ſ�ڴ�ˮ���Ϲ�ཹ�ཹ��˼���ˮ��\n"
            , environment(me), ({me}) );
            write("��ſ�ڴ�ˮ���Ϲ�ཹ�ཹ��˼���ˮ��\n");
        }
        else write("С�Ů��ֵص����㣬�������ֿ��죬������Ц���������Ӷ����˻��ȣ�\n");

        return 1;
}


