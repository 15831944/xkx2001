//Cracked by Roath
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "ǰԺ");
	set("long", @LONG
���ǰ���ɽׯ��ǰԺ��Ժǽ��ש���ߣ�ǽ�Ͽ������಻��������
���ƣ�ټ���ɽׯ͸��һ�ɹ��ܵĸо��������ǰ���ɽׯ�Ĵ�������
�����߸���һ��С��������������֮�ᣬ������ɽȥ����ɽ�š�Ժ��
��һ�����ʯ��ɵĵ�ʯ����
LONG
	);
	set("exits", ([ 
	    "eastdown" : "/d/xingxiu/btgate",
	    "west" : "/d/baituo/dating",
	    "north" : "/d/baituo/road1",
	    "south" : "/d/baituo/road2",
	]));
	set("objects", ([
	    "/d/baituo/npc/binu" : 1,
	    "/d/baituo/npc/jiading" : 1,
	 ]) );
	set("outdoors","baituo");
	replace_program(ROOM);
	set("cost", 1);
	setup();
	"/clone/board/baituo_b"->foo();
}
