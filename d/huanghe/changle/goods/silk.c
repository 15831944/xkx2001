//Cracked by Roath
// /d/huanghe/changle/obj/silk.c
// by aln  2 / 98

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(CYN"���"NOR, ({ "silk" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", 
"����һƥ�������俼���ĳ�С�\n");
                set("unit",  "ƥ");
                set("value",  100000000);
                set("material", "silk");
        }
        setup();
}
