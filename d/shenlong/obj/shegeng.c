//Cracked by Roath
// shegeng.c �߸�

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�߸�", ({"shegeng", "geng"}));
	set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("long", "һ��ŨŨ���߸�������!��\n");
		set("unit", "��");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
//		set("drink_supply", 50);

	}
}
