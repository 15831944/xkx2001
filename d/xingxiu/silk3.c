//Cracked by Roath
// /d/xingxiu/silk3.c
// Ryu 

inherit ROOM;

// int do_climb();

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
������ԭ�������ͨ������ɳ����ء����������Ĵ�ɳĮ�ϣ�������
������ǰ���졣��Զ�������������ޱ��޼ʵ�ããɳ���ϣ�����������
ɳ����ʱ������ڿն������Ұ���������أ���Х������һ�����
���������̽���Զ�У�����ɢȥ��
LONG
        );
        set("outdoors", "xingxiuhai");

        set("exits", ([
                "southeast" : __DIR__"silk2",
		"west" : __DIR__"silk4",
        ]));
        set("item_desc", ([
                "mount" : 
        "����һ����ɳ�ѻ��γɵ�ɽ��΢�紵����ɳɽ�������˵���������\n" 
	"��������Ȼ�����﷢�����Ե���̾��\n"
        ]) );

	set("cost", 2);
        setup();
}

/*void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="mount") {
                message("vision",
		me->name() + "�ԳԿԳ���ɳɽ����ȥ��\n",
                environment(me), ({me}) );
                me->move("/d/xingxiu/shashan");
                message("vision",
                me->name() + "��ɳɽ������������ճ��һ��ɳ�ӡ�\n",
                environment(me), me );
                return 1;
        }
}
*/
