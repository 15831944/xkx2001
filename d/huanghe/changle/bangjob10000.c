//Cracked by Roath
// /d/huanghe/changle/bangjob10000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "����������",
                "file"  :  "/d/quanzhou/npc/trader",
                "area"  :  "Ȫ�ݰ�����լ��",
                "type"  :  "ɱ",
                "bonus" :  10,
                "score" :  4,
        ]),

        ([      "name"  :  "��˹����",
                "file"  :  "/d/xingxiu/npc/trader",
                "area"  :  "��ɽ����",
                "type"  :  "ɱ",
                "bonus" :  20,
                "score" :  6,
        ]),

        ([      "name"  :  "��åͷ",
                "file"  :  "/d/quanzhou/npc/liumangtou",
                "area"  :  "Ȫ�ݽֵ�",
                "type"  :  "ɱ",
                "bonus" :  15,
                "score" :  8,
        ]),

        ([      "name"  :  "��һ��",
                "file"  :  "/d/forest/npc/gaiyiming",
                "area"  :  "���ݽ���",
                "type"  :  "ɱ",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "�����",
                "file"  :  "/d/huanghe/npc/shen-qinggang",
                "area"  :  "�ƺӰ�",
                "type"  :  "ɱ",
                "bonus" :  20,
                "score" :  10,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/huanghe/npc/wu-qinglie",
                "area"  :  "�ƺӰ�",
                "type"  :  "ɱ",
                "bonus" :  18,
                "score" :  9,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/huanghe/npc/ma-qingxiong",
                "area"  :  "�ƺӰ�",
                "type"  :  "ɱ",
                "bonus" :  16,
                "score" :  8,
        ]),

        ([      "name"  :  "Ǯ�ཡ",
                "file"  :  "/d/huanghe/npc/qian-qingjian",
                "area"  :  "�ƺӰ�",
                "type"  :  "ɱ",
                "bonus" :  15,
                "score" :  7,
        ]),

        ([      "name"  :  "����ɢ",
                "file"  :  "/d/xingxiu/obj/xxqingxin-san",
                "type"  :  "Ѱ",
                "bonus" :  12,
                "score" :  4,
        ]),

        ([      "name"  :  "��ʬ��",
                "file"  :  "/d/xingxiu/obj/huashi",
                "type"  :  "Ѱ",
                "bonus" :  15,
                "score" :  5,
        ]),

        ([      "name"  :  "�ٲݵ�",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  30,
                "score" :  8,
        ]),

        ([      "name"  :  "�ۻ���",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  30,
                "score" :  8,
        ]),

        ([      "name"  :  "����",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  30,
                "score" :  8,
        ]),

        ([      "name"  :  "��Ѫ��",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  30,
                "score" :  8,
        ]),

        ([      "name"  :  "�˲ι�",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  60,
                "score" :  16,
        ]),

        ([      "name"  :  "���ھ�",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  30,
                "score" :  8,
        ]),

        ([      "name"  :  "�����赨ɢ",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  30,
                "score" :  8,
        ]),

        ([      "name"  :  "�޳���",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  30,
                "score" :  8,
        ]),

        ([      "name"  :  "��֥",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  30,
                "score" :  8,
        ]),

        ([      "name"  :  "������",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  30,
                "score" :  8,
        ]),

        ([      "name"  :  "��ɽ��",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  30,
                "score" :  8,
        ]),

        ([      "name"  :  "�˲�",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  40,
                "score" :  10,
        ]),

        ([      "name"  :  "ͨ���",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  10,
                "score" :  2,
        ]),

        ([      "name"  :  "��Ƥ��ҩ",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "¹��ǥ��",
                "file"  :  "/d/changbai/obj/qianzi",
                "type"  :  "Ѱ",
                "bonus" :  20,
                "score" :  8,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/changbai/obj/sbgun",
                "type"  :  "Ѱ",
                "bonus" :  20,
                "score" :  8,
        ]),

        ([      "name"  :  "Ы�ӿ�",
                "file"  :  "/d/xingxiu/npc/scorp_shell",
                "type"  :  "Ѱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/xingxiu/npc/wg_shell",
                "type"  :  "Ѱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "����˿",
                "file"  :  "/d/xingxiu/npc/zhusi",
                "type"  :  "Ѱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "ɳ���",
                "file"  :  "/d/xingxiu/npc/shachongke",
                "type"  :  "Ѱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "���ߵ�",
                "file"  :  "/d/xingxiu/npc/obj/shedan",
                "type"  :  "Ѱ",
                "bonus" :  10,
                "score" :  3,
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}


