//Cracked by Roath
// /d/huanghe/bangjob/bangjob5000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "��ͷ",
                "file"  :  "/d/city/npc/biaotou",
                "area"  :  "���ݸ����ھ�",
                "type"  :  "ɱ",
                "bonus" :  20,
                "score" :  6,
        ]),

        ([      "name"  :  "�Ҷ�",
                "file"  :  "/d/city/npc/jiading",
                "area"  :  "���ݺ��ָ�Ժ",
                "type"  :  "ɱ",
                "bonus" :  15,
                "score" :  3,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/city/npc/juyou",
                "area"  :  "���ݺ��ָ�Ժ",
                "type"  :  "ɱ",
                "bonus" :  15,
                "score" :  4,
        ]),

        ([      "name"  :  "��С��",
                "file"  :  "/d/village/npc/wang",
                "area"  :  "��ɽ��",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  15,
        ]),

        ([      "name"  :  "�ػ�",
                "file"  :  "/d/quanzhou/npc/huihui",
                "area"  :  "Ȫ��",
                "type"  :  "ɱ",
                "bonus" :  18,
                "score" :  4,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/hangzhou/npc/tbbz",
                "area"  :  "�����庣��",
                "type"  :  "ɱ",
                "bonus" :  15,
                "score" :  4,
        ]),

        ([      "name"  :  "��ɳ������",
                "file"  :  "/d/hangzhou/npc/hsbz",
                "area"  :  "����������",
                "type"  :  "ɱ",
                "bonus" :  18,
                "score" :  5,
        ]),

        ([      "name"  :  "��ӥ����",
                "file"  :  "/d/hangzhou/npc/tyjz",
                "area"  :  "�����庣����",
                "type"  :  "ɱ",
                "bonus" :  20,
                "score" :  5,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/city/obj/lingpai",
                "type"  :  "Ѱ",
                "bonus" :  8,
                "score" :  2,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/dali/npc/obj/kandao",
                "type"  :  "Ѱ",
                "bonus" :  8,
                "score" :  2,
        ]),

        ([      "name"  :  "��Ͳ",
                "file"  :  "/d/dali/obj/zhutong",
                "type"  :  "Ѱ",
                "bonus" :  8,
                "score" :  2,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/clone/weapon/hammer",
                "type"  :  "Ѱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "���Ĵ���",
                "file"  :  "/d/dali/npc/obj/wyhui",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  10,
        ]),

        ([      "name"  :  "���ĳ�ȹ",
                "file"  :  "/d/dali/npc/obj/wyskirt",
                "type"  :  "Ѱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "���",
                "file"  :  "/d/xingxiu/obj/bian",
                "type"  :  "Ѱ",
                "bonus" :  12,
                "score" :  4,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/xingxiu/obj/changbian",
                "type"  :  "Ѱ",
                "bonus" :  15,
                "score" :  5,
        ]),

        ([      "name"  :  "��˹����",
                "file"  :  "/d/xingxiu/obj/changpao",
                "type"  :  "Ѱ",
                "bonus" :  8,
                "score" :  3,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/xingxiu/obj/dongbula",
                "type"  :  "Ѱ",
                "bonus" :  10,
                "score" :  4,
        ]),

        ([      "name"  :  "�ɺ�ҩ",
                "file"  :  "/d/xingxiu/obj/menghan_yao",
                "type"  :  "Ѱ",
                "bonus" :  6,
                "score" :  2,
        ]),

        ([      "name"  :  "��ʬ��",
                "file"  :  "/d/xingxiu/obj/huashi",
                "type"  :  "Ѱ",
                "bonus" :  12,
                "score" :  5,
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}


