//Cracked by Roath
// room: zhuquetan.c

inherit ROOM;

void create()
{
        set("short", "朱雀坛");
        set("long", @LONG
这里是天鹰教五坛之一的朱雀坛。大厅正面高悬一块牌匾，上书
两个烫金大字“朱雀”，由教主亲提。厅里摆着一面屏风，屏风上画
着一副朱雀图，甚是威风。
LONG );

        set("exits", ([
                "north" : __DIR__"zoulang4",
        ]));

        setup();
        replace_program(ROOM);
}
