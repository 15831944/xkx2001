//Cracked by Roath
//Kane

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ǰ��һ��ׯԺ����¥�����ߴ���ש���ߣ���ɫ�׵�����д��
������ׯ����������֡����ҽ�Ϊ�¾ɣ��߽Ǵ�����Ƥ�Ѱ��䣬¶��
����ɫ��ľ�ʡ������������Ѳ��¶�ʮ�������ˡ�
LONG
	);
	 set("exits", ([
		"enter" : __DIR__"qianyuan",
		"south" : __DIR__"matou",
	]));
	set("cost", 1);
	set("outdoors", "taihu");
	set("objects", ([
		"/d/taihu/npc/jiading" : 2,
	]));

	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    mapping myfam = (mapping)me->query("family");

    if ( (!myfam || myfam["family_name"] != "�һ���") && (dir == "enter") && (!me->query_temp("guiyun")) && present("jia ding", environment(me)))
	return notify_fail("�Ҷ����˸�Ҿ��˵����������ׯ����������ׯ��������ͣ�������ذ�\n");

    return ::valid_leave(me, dir);
}
