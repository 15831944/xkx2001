//Cracked by Roath
// Room: /d/xixia/dangpu.c

inherit ROOM;

void create()
{
	set("short", "���浱��");
	set("long", @LONG
���Ǽ�Զ�������ĵ��̣�����������棬һ��д�š����浱�̡�
�ĸ����ֵĺ��ң������߳߸ߵ���̴ľ�Ĺ�̨��ĥ�ù�����ˣ���̨
����ϳ���ͷҲ��̧��ֻ�˲��������̣���̨�Ϸ�����һ�����ӣ���
�飺"������Ը���Ų���Ƿ"��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"nandajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
