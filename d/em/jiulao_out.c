//Cracked by Roath
// d/emei/jiulao_out.c ���϶���
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "Сɽ��");
	set("long", @LONG
��ǰ��Ȼһ����ԭ���Ǿ��϶����һ��Сɽ�¡�ɽ�����Ӳݴ�������ܴ�
�ε���֦��ҡ��һ�ù����·��ż������ã����涼���������ָ������������
ɭɭ�ġ�
LONG
	);

        set("exits", ([
                "north" : __DIR__"jiulao1",
        ]));

        set("objects",([
		"/kungfu/class/emei/zhou.c" :1,
        ]));

	set("invalid_startroom", 1);

	set("outdoors", "emei" );
	set("cost", 1);
	setup();
}


