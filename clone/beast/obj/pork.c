//Cracked by Roath
// pork.c ����
// xbc 06/21/97

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("С������", ({"zhu erduo", "zhu rou", "pork"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��С�������⡣\n");
		set("unit", "��");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 20);
	}
}
