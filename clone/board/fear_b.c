//Cracked by Roath
// /clone/board/fear_b.c
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
	set_name(HIR"�ֲ�����"NOR, ({ "board" }) );
	set("location", "/u/fear/workroom");
	set("board_id", "fear_b");
	set("long", "����һ�������̸�۸��ֻ�������԰塣\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

