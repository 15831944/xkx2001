//Cracked by Roath

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIW"��Ƥ��"NOR, ({ "qiu pi'ao", "ao" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "����һ��ѩ�׵���Ƥ����\n");
                set("unit", "��");
                set("value", 1700);
                set("material", "fur");
                set("armor_prop/armor", 10);
        }
        setup();
}

