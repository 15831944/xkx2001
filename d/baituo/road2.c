//Cracked by Roath
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
һ������ɳʯ��С��������ͨ��ɽׯ��ǰԺ�����ϱ���һ��С��
������Ʈ������Ʋ�������
LONG
	);
	set("exits", ([ 
	    "southwest" : __DIR__"kitchen",
	    "north" : "/d/xingxiu/btyard",
	]));
	set("outdoors","baituo");
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
