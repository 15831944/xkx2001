//Change by Server
// Room: /adm/register/reg_room.c

inherit ROOM;

void create()
{
	set("short", "�����еǼǴ�");
	set("long", @LONG
Ϊ�˸��õع��������У�����Ҫ�����ڽ���������֮ǰ�Ȱ��
�Ǽ����������� register ָ���ڴ˵Ǽǣ���������������ʵ�� email
��������bbs email����ǧ�����д��������Ը�������ڱ�
�Ȱ�ָ��д�ã�������鼸�����copy & paste.

���磬������email��ַ��tu@albert.uwinnpeg.ca
��ʹ�����ָ�register tu@albert.uwinnipeg.ca

Ȼ�����ǻ����һ�����롣

LONG
	);

	set("objects", ([
//		__DIR__"attr" : 1,
//		__DIR__"name" : 1,
		__DIR__"shaoye" : 1,
	]));
        set("exits", ([ /* sizeof() == 1 */
//              "north" : "/adm/guild/meetingroom"
        ]));

	set("invalid_startroom", 1);
	setup();
//	load_object("/daemon/board/wizard");
//	replace_program(ROOM);
}
void init()
{
        object ob = this_player();

        if (!wizardp(ob)) {
                add_action("block_cmd","",1);
//                ob->set("startroom", "/d/death/death");
                ob->set("block", 1);
        }
}

int block_cmd()
{
        string cmd;
        cmd = query_verb();
        if ( cmd == "quit" || cmd == "goto" || cmd == "suicide" || cmd == "register" || cmd == "tell" || cmd == "say" || cmd == "reply" || cmd == "look")
                return 0;
        return 1;
}

