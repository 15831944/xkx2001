//Cracked by Roath
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǰ���ɽׯ�Ĵ��������߳�����Ϊ��������������Ů���ֳֺ�
ɴ����վ�����ԣ�����һ�Ӱ�����Ů�������裬��̬��欣�����������
�ϱ�����һ������ͨ�����ȣ����߰���һ�����磬�������һ��ѩ�׵�
���գ�����Ļ��ȿ������߸�
LONG
	);
	set("exits", ([ 
	    "east" : "d/xingxiu/btyard",
	    "west" : __DIR__"changlang1",
	    "north" : __DIR__"changlang3",
	    "south" : __DIR__"changlang4",
	]));
	set("objects", ([
	    __DIR__"npc/wuji" : 3,
	 ]) );
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
