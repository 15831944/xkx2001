//Cracked by Kafei
// /clone/board/gumu_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��Ĺ�������԰�", ({ "board" }) );
	set("location", "/d/zhongnan/dating");
	set("board_id", "gumu_b");
	set("long", "����һ������Ĺ�ɵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

