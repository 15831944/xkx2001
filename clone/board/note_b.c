//Cracked by Roath
// /clone/board/note_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ʦ���԰�", ({ "board"}) );
	set("location", "/d/death/noteroom");
	set("board_id", "note_b");
	set("long", "����һ�����ʦ��¼��ҷ���ԭ������԰塣\n" );
	setup();
	set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}

