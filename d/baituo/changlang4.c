//Cracked by Roath
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ����ש��ǽ�ĳ��ȣ����ߵĹ���ͨ������������һ��ľ�ţ���
ͷ�ǰ���ɽׯ����ʦ��ס�ķ��䡣���ϱ�����һ��С�ţ����ǼҶ���
�Ů����������Ϣ�����ڡ����ϱߵ�����Ʈ��������ζ���ǰ���ɽׯ
�ĳ�����
LONG
	);
	set("exits", ([ 
	    "north" : __DIR__"dating",
	    "west" : __DIR__"bedroom2",
	    "southwest" : __DIR__"bedroom3",
	    "southeast" : __DIR__"kitchen",
	]));
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
