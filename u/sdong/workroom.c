//Cracked by Kafei
inherit ROOM;
#include <ansi.h>
void reset();
int valid_leave();

void create()
{
		  set("short", HIG"��լ"NOR);
		  set("long", @LONG
�����Ƕ����ĺ�լ���Ĵ���̻Ի͡�ǽ����ʱ�շ�������
---------------------------------------------------------------
	 ����: sl      �䵱: wn      ����: xx     ؤ��: gb     ����: bt
	 ��ɽ: hs      ����: xk      �͵�: kd     ѩɽ: xs     ����: em
	 ����: dl      ����: sn      ����: xi     �һ�: td     ����: gy

	 ����: cls     �˽�: xbc     ����: qfy    �ǿ�: kane   ����: dg
	 ����: marz    �ɹ�: mgl     ����: xuy    ���: lyu    è��: ox
	 �鷿: aln     ����: chu     �Է�: ssy    ��̶: long   ����: acep

---------------------------------------------------------------
LONG
		  );

		  set("exits", ([
					 "sl" : "/d/shaolin/guangchang1",
		"sn" : "/d/shenlong/tingkou",
		"xi" : "/d/xixia/dawu",
		"hz" : "/d/hangzhou/kedian",
					 "wn" : "/d/wudang/sanqingdian",
		"xk" : "/d/xiakedao/dadong",
					 "xx" : "/d/xingxiu/xxh2",
					 "gb" : "/d/gaibang/undertre",
		"gb2" : "/d/gaibang/gbxiaowu",
		"gy" : "/d/taihu/qianyuan",
					 "kd" : "/d/city/kedian",
					 "qz" : "/d/quanzhou/zhongxin",
		"hs" : "/d/huashan/pianting",
		"bt" : "/d/xingxiu/btyard",
		"wr" : "/d/wizard/meeting_room",
		"wz" : "/d/wizard/wizard_room",
		"dl" : "/d/dali/wangfu1", 
		"em" : "/d/emei/hz_guangchang",
		"xs" : "/d/xueshan/guangchang",
		"qfy" : "/u/qfy/workroom",
		"lyu" : "/u/lyu/workroom",
		"kane" : "/u/kane/workroom",
		"xbc" : "/u/xbc/workroom",
		"ssy" : "/u/ssy/workroom",
		"cls" : "/u/cleansword/workroom",
		"rover" : "/u/rover/workroom",
		"marz" : "/u/marz/workroom",
		"acep" : "/u/acep/workroom",
		"long" : "/u/long/workroom",
		"chu" : "/u/chu/workroom",
		"aln" : "/u/aln/workroom",
		"mgl" : "/u/mongol/workroom",
		"xuy" : "/u/xuy/workroom",
		"ox" : "/u/oyxb/workroom",
		"dg" : "/u/ding/workroom", 
		"td" : "/d/taohua/jingshe",
		"leitai":"u/xuy/bwdh/leitai.c",
		"up" : "/u/sdong/library",
        ]));
	set("objects", ([
                __DIR__"obj/renshen-guo" : 1,
                __DIR__"obj/atm" : 1,
					 __DIR__"npc/yahuan.c" : 1,
		  ]));

		  set("valid_startroom",1);

        setup();
}
int valid_leave(object me, string dir)
{
		  if ( !wizardp(me) && dir!="up" ){
					 return notify_fail("Ѿ��һ�Ѿ�ס�������˵�������ţ����Դ�û�����������ߣ���\n");
	}
        return ::valid_leave(me, dir);
}

