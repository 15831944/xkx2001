//Cracked by Roath
// /clone/board/leitai_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��̨����ǽ", ({ "wall" }) );
	set("location", "/d/quanzhou/leitai2");
	set("board_id", "leitai_b");
	set("long", "������̨��һ���������ָ�ʾ�������Ĵ�ǽ��\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

