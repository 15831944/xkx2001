//Cracked by Roath
// /clone/board/progress_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�����н��ȱ�", ({ "board" }) );
	set("location", "/d/wizard/meeting_room");
	set("board_id", "progress_b");
	set("long", "����һ������������ʦ�ǻ㱨�����ƻ��Լ����ȵ����԰塣\n" );
	set("wizard_only", 1);
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

