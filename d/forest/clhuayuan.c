//Cracked by Roath
// changle/clhuayuan.c

inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
�����԰�ǵ��͵Ľ��Ϸ�񣬾���ϸ�¡�԰�л�����û��ʲô����
Ʒ�֣�Ҳ�����涷��������һ��ʯ���̾͵�С·������鲼��̦������
ʪ��������һ������
LONG );

        set("exits", ([
		"south" : __DIR__"clbajiaoting",
		"west" : __DIR__"clzoulang2",
		"east" :  __DIR__"clyongdao",
        ]));

        set("cost", 0);

        setup();

        replace_program(ROOM);
}

