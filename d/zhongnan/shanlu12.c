//Cracked by Roath
// road: /zhongnan/shanlu12.c

inherit ROOM;

void create()
{
        set("short","ɽ·");

        set("long",@LONG
����ɽ·������ɽ������ϣ�ɽ·����ʯ������ֻ��һ�˿ɹ�����
�Ƽ�Ϊ�վ�����Զ����ȥ��Ⱥɽ���ƣ���춽��£��������������۵ף���
ʱ���˺�����������Ҫ��Хһ������������һƬ�յء������Ͼ�������ɽ
���塣
LONG);

        set("exits",([ "northup" : __DIR__"shanfeng",
                        "southdown" : __DIR__"kongdi",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
