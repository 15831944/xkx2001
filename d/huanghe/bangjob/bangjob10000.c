//Cracked by Roath
// /d/huanghe/bangjob/bangjob10000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "�ٱ�",
                "file"  :  "/d/city/npc/bing",
                "area"  :  "���ݳ�",
                "type"  :  "ɱ",
                "bonus" :  25,
                "score" :  12,
        ]),

        ([      "name"  :  "�ܼ�",
                "file"  :  "/d/city/npc/guanjia",
                "area"  :  "���ݺ��ָ�Ժ",
                "type"  :  "ɱ",
                "bonus" :  10,
                "score" :  4,
        ]),

        ([      "name"  :  "��ƽ֮",
                "file"  :  "/d/city/npc/linpingzhi",
                "area"  :  "���ݸ����ھ�",
                "type"  :  "ɱ",
                "bonus" :  17,
                "score" :  6,
        ]),

        ([      "name"  :  "��åͷ",
                "file"  :  "/d/city/npc/liumangtou",
                "area"  :  "���ݳ�����",
                "type"  :  "ɱ",
                "bonus" :  12,
                "score" :  5,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/city/npc/yayi",
                "area"  :  "���ݳ�",
                "type"  :  "ɱ",
                "bonus" :  20,
                "score" :  10,
        ]),

        ([      "name"  :  "�ն���",
                "file"  :  "/d/changbai/npc/batou",
                "area"  :  "����ɽ",
                "type"  :  "ɱ",
                "bonus" :  15,
                "score" :  4,
        ]),

        ([      "name"  :  "��һ��",
                "file"  :  "/d/forest/npc/gaiyiming",
                "area"  :  "���ݽ���",
                "type"  :  "ɱ",
                "bonus" :  40,
                "score" :  10,
        ]),

        ([      "name"  :  "�����",
                "file"  :  "/d/huanghe/npc/shen-qinggang",
                "area"  :  "�ƺӰ�",
                "type"  :  "ɱ",
                "bonus" :  20,
                "score" :  6,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/huanghe/npc/wu-qinglie",
                "area"  :  "�ƺӰ�",
                "type"  :  "ɱ",
                "bonus" :  18,
                "score" :  6,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/huanghe/npc/ma-qingxiong",
                "area"  :  "�ƺӰ�",
                "type"  :  "ɱ",
                "bonus" :  16,
                "score" :  5,
        ]),

        ([      "name"  :  "Ǯ�ཡ",
                "file"  :  "/d/huanghe/npc/qian-qingjian",
                "area"  :  "�ƺӰ�",
                "type"  :  "ɱ",
                "bonus" :  15,
                "score" :  5,
        ]),

        ([      "name"  :  "�����",
                "file"  :  "/kungfu/class/gaibang/qiu-wanjia",
                "area"  :  "����ӭ��¥",
                "type"  :  "ɱ",
                "bonus" :  16,
                "score" :  5,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/quanzhou/npc/huren",
                "area"  :  "Ȫ��",
                "type"  :  "ɱ",
                "bonus" :  12,
                "score" :  3,
        ]),

        ([      "name"  :  "����Ŷ�",
                "file"  :  "/d/quanzhou/npc/mending",
                "area"  :  "Ȫ���������",
                "type"  :  "ɱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "ɮ��",
                "file"  :  "/d/quanzhou/npc/monk",
                "area"  :  "Ȫ��",
                "type"  :  "ɱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "����������",
                "file"  :  "/d/quanzhou/npc/trader",
                "area"  :  "Ȫ��",
                "type"  :  "ɱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "�η�����",
                "file"  :  "/d/taishan/npc/seng-ren",
                "area"  :  "̩ɽ",
                "type"  :  "ɱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/wudang/npc/tufei1",
                "area"  :  "�䵱ɽ",
                "type"  :  "ɱ",
                "bonus" :  25,
                "score" :  12,
        ]),

        ([      "name"  :  "�̽�",
                "file"  :  "/clone/weapon/duanjian",
                "type"  :  "Ѱ",
                "bonus" :  8,
                "score" :  2,
        ]),

        ([      "name"  :  "�ֵ�",
                "file"  :  "/clone/weapon/gangdao",
                "type"  :  "Ѱ",
                "bonus" :  8,
                "score" :  2,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/city/npc/obj/junfu",
                "type"  :  "Ѱ",
                "bonus" :  8,
                "score" :  2,
        ]),

        ([      "name"  :  "���۷�",
                "file"  :  "/d/city/npc/obj/yayifu",
                "type"  :  "Ѱ",
                "bonus" :  8,
                "score" :  2,
        ]),

        ([      "name"  :  "�̵�",
                "file"  :  "/d/dali/obj/duandao",
                "type"  :  "Ѱ",
                "bonus" :  15,
                "score" :  5,
        ]),

        ([      "name"  :  "�������",
                "file"  :  "/d/forest/npc/obj/dahong-jiasha",
                "type"  :  "Ѱ",
                "bonus" :  15,
                "score" :  5,
        ]),

        ([      "name"  :  "��ü��",
                "file"  :  "/d/forest/npc/obj/emeici",
                "type"  :  "Ѱ",
                "bonus" :  15,
                "score" :  5,
        ]),

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "����",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}


