//Cracked by Roath
// room: /d/xingxiu/btroom
// Jay 10/8/96

inherit ROOM;

void create()
{
        set("short", "Сɽ��");
        set("long", @LONG
����һ��Сɽ��һ��СϪ��ɽ��������һ������û��ʲô���棬
�������֪�ιʳ����������˱�����ҧ���Ĵ��ԡ�
LONG
        );
        set("exits", ([ 
	    "eastdown" : __DIR__"btroad",
        ]));
        set("resource/water", 1);

        set("objects", ([ 
            CLASS_D("baituo")+"/ke" : 1,
	    __DIR__"npc/snake" : 2,
         ]) );
        replace_program(ROOM);
	set("cost", 2);
        setup();
}

