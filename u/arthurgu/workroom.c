//Cracked by Kafei
inherit ROOM;
#include <ansi.h>
void reset();
int valid_leave();

void create()
{
        set("short", MAG"��ζС��"NOR);
        set("long", "
    ����Ѱ���Ĺ�����,��һ�߽�������һ���Ķ��ĸо�,�ƺ�������
������˿.������ȥ,ǽ�Ϲ���һ�ž޴��"+HIW"ͼ��(picture)"NOR+"��������
��ס�࿴����,��̨�������һ���黨,����ɫ������,����ѤĿ.

"

        );

        set("exits", ([
                "sl" : "/d/shaolin/guangchang1",
                "sn" : "/d/shenlong/tingkou",
                "xi" : "/d/xixia/dawu",
                "hz" : "/d/hangzhou/kedian",
                "wud" : "/d/wudang/sanqingdian",
                "xk" : "/d/xiakedao/dadong",
                "xx" : "/d/xingxiu/xxh2",
                "gb" : "/d/gaibang/undertre",
                "gb2" : "/d/gaibang/gbxiaowu",
                "gy" : "/d/taihu/qianyuan",
                "kd" : "/d/city/kedian",
                "qz" : "/d/quanzhou/zhongxin",

                "hs" : "/d/huashan/pianting",
                "bt" : "/d/xingxiu/btyard",
                "dl" : "/d/dali/wangfu1", 
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
                "qfy" : "/u/qfy/workroom",
                "lyu" : "/u/lyu/workroom",
                "kane" : "/u/kane/workroom",
                "xbc" : "/u/xbc/workroom",
                "cls" : "/u/cleansword/workroom",
                "rover" : "/u/rover/workroom",

                "marz" : "/u/marz/workroom",
                "mgl" : "/u/mongol/workroom",
                "xuy" : "/u/xuy/workroom",
                "ox" : "/u/oyxb/workroom",
                "dg" : "/u/ding/workroom", 
                "chu" : "/u/chu/workroom",
                "ssy" : "/u/ssy/workroom",
                "dong" : "/u/sdong/workroom",
                "td" : "/d/taohua/jingshe",
                "yongan" : "/d/beijing/west/yonganmen.c",
                "tianan" : "/d/beijing/zijin/tiananmen",
        ]));
        set("objects", ([
                __DIR__"obj/renshen-guo" : 1,
                __DIR__"obj/fan" : 1,
                __DIR__"obj/namechange" : 1,
                __DIR__"npc/meimei" : 1,
    
        ]));
        set("item_desc", ([
              "picture" :
"
  ---------------------------------------------------------------
    ����: sl      �䵱: wud     ����: xx     ؤ��: gb     ����: bt
    ��ɽ: hs      ����: xk      �͵�: kd     ѩɽ: xs     ����: em
    ����: dl      ����: sn      ����: xi     �һ�: td     ����: gy
   
    
    ����: cls     �˽�: xbc     ����: qfy    �ǿ�: kane   ����: dg
    ����: marz    �ɹ�: mgl     ����: xuy    ���: lyu    è��: ox 
    ��ٸ: chu     ����: dong    ����: ssy
    
             
  ---------------------------------------------------------------
\n",
              ]));

        set("valid_startroom",1);
               
        setup();
        
}

int valid_leave(object me, string dir)
{
        if ((string)me->query("id")!="arthurgu"){
                return notify_fail("��Ϊ��������һ��Ҳ������ȥ��\n");
        }
  
        return ::valid_leave(me, dir);        return 1;
}
