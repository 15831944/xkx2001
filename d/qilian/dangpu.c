//Cracked by Roath
// Room: /d/qilian/dangpu.c

inherit ROOM;

void create()
{
	set("short", "���浱��");
	set("long", @LONG
���Ǽ�Զ�������ĵ��̣�����������棬һ��д�š����浱�̡���
�����ֵĺ��ң������߳߸ߵ���̴ľ�Ĺ�̨��ĥ�ù�����ˣ���̨����
���������ӣ��ֱ�����Ÿ�ʽ����(weapon)�����ߴ���(armor)��ҩ
��(drug)�����(book)����������ʽ����(misc)����̨���̨�����
����ͷҲ��̧��ֻ�˲��������̣���̨�Ϸ�����һ�����ӣ����飺"��
����Ը���Ų���Ƿ"��
LONG
	);
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	 set("no_beg",1);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lanzhou",
]));
	set("objects", ([
		__DIR__"npc/chaofeng" : 1,
	]));
	setup();
	replace_program(ROOM);
}
