//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "���� ");
	set("long",  @LONG
�������Ͻ��ǵ����ţ���������ǰ����ʰ��Σ��׳����¥����
¥�����б��������������ӹ����ȣ�ÿ�곯������ȶ�Ҫ���ӻ��ģ�
������ʿ�����������ʵ۶����Ե�������¥�����ܷ���

����һ����С����¥��ÿ����ʱ����ٹ��Ƽ�������Ⱥ򵱽�
ʥ�ϵ��ټ������߸���һ��ƫ����ٹ���Ϣ�á�����������ʿ�־�
��ǹ����ӧ�����ף��������ݣ�ɱ�����ڡ�
LONG
	);


	set("exits", ([
        "north" : __DIR__"guang2",
        "south" : __DIR__"duanmen",
/*        "west"  : __DIR__"piandian2",                 */
/*       "east"  : __DIR__"piandian1",   �˶���ڴ˴�.*/


	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
};
