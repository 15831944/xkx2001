//Cracked by Roath
// /u/arthurgu/arthurgu_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("Ѱ�����������԰�", ({ "board" }) );
	set("location", "/u/arthurgu/workroom");
	set("board_id", "arthurgu_b");
	set("long", "����һ��Ѱ������ʦ֮�佻���õ�ר�ð塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

