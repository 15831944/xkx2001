//Cracked by Roath
// /clone/board/broker_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("����ͤ������", ({"board",  "zhuzi" }) );
	set("location", "/d/city/yuelao");
	set("board_id", "broker_b");
	set("long", "��������ͤ�����ӣ����������˸���������ʾ��Ѱ����ʾ��\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

