//Cracked by Roath
// baoguo1.c �����´��۵�
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "���۵�");
        set("long", @LONG
�����Ǳ����´��۵�������Ƕ���ɽ�����Ժ֮һ�����۵��ڹ��Ž��
�Ӳӵķ�������������
LONG
        );
        set("exits", ([
                "out" : __DIR__"baoguo",
		"west": __DIR__"baoguo3",
		"north" : __DIR__"baoguo2",
        ]));

        set("objects", ([
                __DIR__"npc/xiang-ke.c": 2,
        ]));

	set("cost", 0);
        setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( me->query("family/family_name") != "������" && dir == "west" ) 
		return notify_fail("����������ֻ�Ӵ����ҵ��ӣ���Ҫ�ǳ�������ڴ˶����ע��ɡ�\n");

	if ( me->query("gender") == "Ů��" && dir == "west" )
		return notify_fail("��λ" + RANK_D->query_respect(me) +
				"�����������е�����Ϣ����������һŮ�Ӳ�̫����ɣ���\n");

	return ::valid_leave(me, dir);
}
