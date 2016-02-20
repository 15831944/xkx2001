//Cracked by Kafei
// qfy's workroom

#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
	set("short",GRN "������" NOR);
	set("long", @LONG
	
�������죬ΡΡ��أ������ҳ��Ρ��������£���ȥ��ȥ�ݣ�

------------------------------------------------------        
��ɽhs��Ȫ��qz������yz��̩ɽts������sl���䵱wd������ql
ؤ��gb������xx������em������bt��ѩɽxs������kl������sn  
����xi������gy������dl������hz������er����ʦwr
------------------------------------------------------

LONG
	);
	set("no_fight", 1);
	set("objects", ([
		__DIR__"yumiko" : 1,
	]));
					      
	set("valid_startroom",1);
					      
	set("exits", ([
                "kl" : "/d/kunlun/wall5",
                "sl" : "/d/shaolin/guangchang1",
                "sn" : "/d/shenlong/tingkou",
                "xi" : "/d/xixia/dawu",
                "hz" : "/d/hangzhou/kedian",
                "wd" : "/d/wudang/sanqingdian",
                "xx" : "/d/xingxiu/xxh2",
                "gb" : "/d/gaibang/undertre",
                "gy" : "/d/taihu/qianyuan",
                "hs" : "/d/huashan/buwei1",
                "bt" : "/d/xingxiu/btyard",
                "dl" : "/d/dali/wangfu1",
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
		"yz" : "/d/city/kedian",
                "qz" : "/d/quanzhou/zhongxin",
                "hs" : "/d/huashan/buwei1",
                "bt" : "/d/xingxiu/btyard",
                "dl" : "/d/dali/wangfu1",
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
                "wr": "/d/wizard/meeting_room",                                                             
	]));

	setup();
	//replace_program(ROOM);
}

void init()
{
	object me = this_player();

	if( wizardp(me) && getuid(me)!="qfy ")
		message("vision", me->name()+"���˹�����\n", environment(me), ({me}));

	add_action("do_leave", "leave");
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me))
		return notify_fail("�����ӵ�������ǰ������˵�������ǳ���Ǹ�������ܵ��Ƕ�ȥ����\n");

	return ::valid_leave(me, dir);
}

int do_leave()
{
	object me = this_player();
	if(me)
		me->move("/d/city/wumiao");
	return 0;
}
