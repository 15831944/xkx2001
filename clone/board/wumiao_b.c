//Cracked by Roath
// /clone/board/wumiao_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("�����ʾ��", ({ "board" }) );
        set("location", "/d/city/wumiao");
        set("board_id", "wumiao_b");
        set("poster_level", "(apprentice)");
        set("long", "���ǹ���ʦ����ʾ�õģ���Ҳ���������\n");
        set("intermud", 1);
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}

