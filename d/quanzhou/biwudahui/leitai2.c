//Cracked by Roath
// /d/quanzhou/leitai2.c ��̨һ��
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "��̨һ��");
	set("long", @LONG
������̨�����һ��յء�С̯�����ڴ˰�̯����������������ҩ��
���⡣�е�̯�ϻ����˴�ˮͰ���������������ṩ��ˮ��һ����ˢ��ǽ��
���������Ŵ��СС�Ĳ��棬��඼�ǹ��ڽ����ڴ˾��е����ִ�����
�����ܶ���Χ��ǽǰ���ţ�һ�濴һ����������š�
LONG
	);
	set("exits", ([
		"west" : __DIR__"leitai",
		"southwest" : __DIR__"leitai_gate",
	]));

        set("objects",([
                __DIR__"npc/seller2" : 1,
        ]));

//        set("outdoors", "quanzhou" );

        set("valid_startroom", 1);
        set("resource/water", 1);
	set("no_fight", 1);
	set("cost", 0);
	setup();
//	replace_program(ROOM);
        "/clone/board/leitai_b"->foo();

}
int valid_leave(object me, string dir)
{
        if( dir=="west" && !wizardp(me) )
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}

