// Room: /d/wizard/wizard_room.c
//Change by Server (7/26/2001)
inherit ROOM;

void create()
{
	set("short", "��ʦ��Ϣ��");
	set("long", @LONG
���������Ϸ����ʦ����Ϣ�����ڡ����Ӳ��õ����ű��£�����ǽ��������
�������ֻ���������̴ľ�η��ڴ��ߣ��������Ĵ��������Կ�����Ϸ�еĳ�����
���Ų�Զ�������ϰڷ���һ����ʦ���Բ�(board)��
LONG );

	set("exits", ([
        "down" : __DIR__"guest_room" ]));

	set("valid_startroom", 1);
	set("no_fight", "1");
	set("no_clean_up", 0);
	set("cost", 0);
	setup();

	call_other("/clone/board/wiz_b", "???");
//	replace_program(ROOM);
}

void init()
{
	object me = this_player();

	if (wizhood(me) == "(player)")
		me->move("/d/death/death.c");
}
