//Cracked by Roath
// hui-cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("�಼��", ({ "bu yi", "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 8);
        }
        setup();
}

