//Cracked by Roath
// qianting.c
// qfy July 30, 1996.

inherit ROOM;

void create()
{
        set("short", "ǰ��");
	set("long", @LONG
ǰ���ǹ�ǰ��Ͷʦ���ӵ��ǵǼ����á�������Ȼ���ס��������Ÿ�������
�ź�̴ľ�����ӺͲ輸������������λ�������һ������ʯ������磬����һ
��һ���������Ѽ���ǽ���ֹ��м�����ˮ���࣬�ƺ�������ʽ���˲��Ǵ���һ
����򡣰�ʦѧ�յ��ӵ����ڴ˸���ѧ�Ѻ��ɽ������ѧϰ�Լ�������Ȥ��
����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "west" : __DIR__"zoulang1",
            "east" : __DIR__"kaojiao",
	]));

        set("objects", ([ 
	    __DIR__"npc/mawude" : 1,	
        ]));

        set("no_clean_up", 0);
	set("valid_startroom",1);

	set("cost", 1);
        setup();

	"/clone/board/wuguan_b"->foo();
}
