//Cracked by Kafei
// Room: workroom.c
// CLEANSWORD

#include <ansi.h>

inherit ROOM;

void create()
{

	set("short", "��ƽ��������");
	set("long", @LONG
	��������ƽ���Ĺ����ҡ�������ں����ģ���һֻ�����˰�ߵĵ���
���ڿ��е�����ȥ���ذ����ʧ�ޣ�����ȥ֨ѽ֨ѽ���졣һ�Ѷ���һ���ȵĵ�
��б����ǽ�Ǳߡ����϶����˸��ָ����������õĳ�����Щ�Ѿ����˺þã���
��ʼ��ù�����ˡ�
LONG
	);


	set("valid_startroom",1);

	set("exits", ([
                "hs" : "/d/huashan/buwei1",
                "kd" : "/d/city/kedian",
                "sl" : "/d/shaolin/guangchang1",
                "wg" : "/d/wudang/sanqingdian",
                "gb" : "/d/gaibang/undertre",
                "xx" : "/d/xingxiu/xxh2",
                "wz" : "/d/wizard/guest_room",
                "xs" : "/d/xueshan/guangchang",
                "bt" : "/d/xingxiu/btyard",
                "em" : "/d/emei/hz_guangchang",
                "sg" : "/d/shenlong/tingkou",
                "dl" : "/d/dali/wangfu1",
                "th" : "/d/taihu/qianyuan",
	]));

	setup();
//	replace_program(ROOM);

}

void init()
{
	if(this_player()->query("id") == "cleansword") {
		this_player()->set("title",HIR"һ��"HIW"ɱ"HIR"ʮ�ˣ����ﲻ����"NOR);
		this_player()->set("nickname",HIW"֮"HIY"����Ǭ��"NOR);
	}
}


