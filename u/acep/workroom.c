//Cracked by Kafei
// acep's workroom ^_^
inherit ROOM;

void create()
{
	set("short", "���еļ�");
	set("long", @LONG
�����Ƿ��еĹ����ң����������������ذ��������˰����ĸ�
���鼮�������������Ŵ����� (table)���Ա��м���ɳ����һ���輸
���һ�����䡣
LONG);

	set("item_desc", ([
		"table"   : "����һ̨�����⣬û�����ģ�ͺͳ�����ҵض��ţ����м������µ���־��\n",
		]));

	set("exits", ([
		"kd"  : "/d/city/kedian",
		"down"   : "/d/wizard/wizard_room",
		"sl" : "/d/shaolin/guangchang1",
		"wn" : "/d/wudang/sanqingdian",
		"xx" : "/d/xingxiu/xxh2",
		"gb" : "/d/gaibang/undertre",
		"gb2" : "/d/gaibang/gbxiaowu",
		"kd" : "/d/city/kedian",
		"qz" : "/d/quanzhou/zhongxin",
        "hs" : "/d/huashan/buwei1",
        "bt" : "/d/xingxiu/btyard",
        "dl" : "/d/dali/wangfu1", 
        "em" : "/d/emei/baoguomen",
        "em1" : "/d/emei/hz_guangchang",
        "xs" : "/d/xueshan/guangchang",
		"qfy" : "/u/qfy/workroom",
		"lyu" : "/u/lyu/workroom",
		"xbc" : "/u/xbc/workroom",
		"cls" : "/u/cleansword/workroom",
		"rover" : "/u/rover/workroom",
		"marz" : "/u/marz/workroom",
		"mgl" : "/u/mongol/workroom",
        "ryu" : "/u/ryu/workroom",
		]));

	set("valid_startroom", 1);

    setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && dir != "kd")
		return notify_fail("����ǰһ�ߣ�ȴ���������ε����������㣬����ȥ��:(\n");
	return ::valid_leave(me, dir);
}
