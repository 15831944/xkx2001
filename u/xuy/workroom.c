//Cracked by Kafei
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", HIW"������"NOR);
        set("long", @LONG

	baituo	����ɽ 		yuelao	����ͤ 		dali	�����
	emei	����ɽ 		gaibang	ؤ�� 		gbr	ؤ�ﱨ�� 	
	huashan	��ɽ 		kedian	���ݿ͵� 	xueshan	ѩɽ 		
	leitai	��̨ 		prog	���ȱ� 		shaolin	������ 		
	shenlong������ 		towiz	����� 		wiz	��ʦ 		
	wudang	�䵱ɽ 		wuguan	Ȫ����� 	wumiao	���� 		
	xingxiu	���޺� 		xuanjie	���ٽ�		taohua  �һ�

LONG );
        set("valid_startroom",1);
	set("exits", ([
		"taohua": "/d/taohua/jingshe",
		"baituo": "/d/xingxiu/btyard",
		"yuelao": "/d/city/yuelao",
		"dali": "/d/dali/wangfu1",
		"emei": "/d/emei/hz_guangchang",
		"gaibang": "/d/gaibang/undertre",
		"gbr": "/d/gaibang/gbxiaowu",
		"huashan": "/d/huashan/pianting",
		"kedian": "/d/city/kedian",
		"xueshan": "/d/xueshan/guangchang",
		"leitai": "/u/xuy/bwdh/leitai",
		"prog": "/d/wizard/meeting_room",
		"shaolin": "/d/shaolin/guangchang1",
		"shenlong": "/d/shenlong/tingkou",
		"towiz": "/d/wizard/guest_room",
		"wiz": "/d/wizard/wizard_room",
		"wudang": "/d/wudang/sanqingdian",
		"wuguan": "/d/quanzhou/qianting",
		"wumiao": "/d/city/wumiao",
		"xingxiu": "/d/xingxiu/xxh2",
		"guiyun": "/d/taihu/qianyuan",
		"xuanjie": "/d/qilian/datang",
        ]));

//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if ( !wizardp(me) && (dir == "wiz" || dir == "prog") )
                return notify_fail("������ʦ����׼ȥ��\n");
        return ::valid_leave(me, dir);
}
