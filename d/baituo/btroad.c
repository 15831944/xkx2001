//Cracked by Roath
// room: /d/xingxiu/btroad
// Jay 10/8/96

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
���������ݳ����һ��С·������ɭȻ�������и�С���𣬶�����ͨ������
�ǵĹٵ���
LONG
        );
        set("exits", ([ 
            "east" : __DIR__"xxroad2",
            "westup" : __DIR__"bthill",
        ]));
        set("objects", ([ 
            CLASS_D("baituo")+"/ma" : 1,
	    CLASS_D("baituo")+"/binu" : 2,
         ]) );
        set("outdoors","xingxiuhai");

	set("cost", 1);
        setup();
}
int valid_leave(object me, string dir)
{
   if (dir =="westup" && me->query("family/family_name")!="����ɽ" ) {
        if (objectp(present("binu", environment(me))))
                return notify_fail(
	"�Ů���ֵ�ס�����ȥ·����ׯ�����ڵ�ѵ���ߣ������������\n");

        if (objectp(present("qian yankai", environment(me))))
                return notify_fail(
	"������һ���ֵ�ס�����ȥ·����ׯ�����ڵ�ѵ���ߣ������������\n");
   }      
   return ::valid_leave(me, dir);
}

