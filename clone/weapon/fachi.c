//Cracked by Roath

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("����", ({ "fa chi", "chi" }));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ߣ����з�����\n");
		set("value", 250);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(15);
	setup();
}
