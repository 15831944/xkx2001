//Cracked by Roath
// /d/huanghe/bangjob/bangjob500000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "����ͬ",
                "file"  :  "/d/city/npc/yutong",
                "area"  :  "�����ᶽ��",
                "type"  :  "ɱ",
                "bonus" :  60,
                "score" :  20,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/city/npc/dingdian",
                "area"  :  "���ݳǼ���",
                "type"  :  "ɱ",
                "bonus" :  90,
                "score" :  35,
        ]),

        ([      "name"  :  "½��ֹ",
                "file"  :  "/d/city/npc/gaozhi",
                "area"  :  "�����ᶽ��",
                "type"  :  "ɱ",
                "bonus" :  90,
                "score" :  45,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/city/npc/shi",
                "area"  :  "���ݳǱ�Ӫ",
                "type"  :  "ɱ",
                "bonus" :  60,
                "score" :  30,
        ]),

        ([      "name"  :  "��һ��",
                "file"  :  "/d/changbai/npc/teng",
                "area"  :  "�ض�",
                "type"  :  "ɱ",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/huanghe/npc/peng-lianhu",
                "area"  :  "�ƺӰ�",
                "type"  :  "ɱ",
                "bonus" :  40,
                "score" :  15,
        ]),

        ([      "name"  :  "����ͭ��",
                "file"  :  "/d/changbai/obj/tongren",
                "type"  :  "Ѱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "��צ",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  6,
        ]),

        ([      "name"  :  "�պ������",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  6,
        ]),

        ([      "name"  :  "������",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  6,
        ]),

        ([      "name"  :  "������",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  30,
                "score" :  8,
        ]),

        ([      "name"  :  "��ս�",
                "file"  :  "/d/changbai/obj/qinggang-jian",
                "type"  :  "Ѱ",
                "bonus" :  30,
                "score" :  15,
        ]),

        ([      "type"  :  "ʾ��",
        ]),

        ([      "type"  :  "ʾ��",
        ]),

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "����",
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
