//Cracked by Roath
// road: /zhongnan/baimatan.c

inherit ROOM;

void create()
{
        set("short", "����̶");
        set("long", @LONG
���̶Ϊ�����ɽ����һ����һ�����п����ӵ����Ρ�̶����һ���
���䷿�ӻ�Ҫ��İ�ʯͷ����ʯͷ�м����ͷ�ߣ�ʯͷ��ǰ�������ˮ�
�������ڰ��ϡ�������ˮ�е��ǰ��ʯͷ���滹��ʱð��һ������ĭ��
��Զ��ȥ����һƥ�ڿ����ɵ�������˵����˶��д�̶Ϊ����̶��������
һ����᫵�ɽ·��
LONG
        );
        set("outdoors", "zhongnan");

        set("exits", ([
                "northup" : __DIR__"shanlu7",
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
