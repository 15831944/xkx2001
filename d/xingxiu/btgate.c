//Cracked by Roath
// room: /d/xingxiu/btshan
// Jay 3/27/96
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "����ɽɽ��");
	set("long", @LONG
���Ǵ�˵�����صİ���ɽ��ԶԶ��ȥ��������ɳ�ѻ��γɵ�ɽ���
��һֻ���յļ�����һ��ɽ�����������ǰ��ɽ�ź�һ�����ͨ��һ��
ɽ���ϵ�ɽׯ�������ǡ�������ŷ����İ���ɽׯ������һ��С·����
ͨ��������
LONG
	);
	set("exits", ([ 
	    "east" : __DIR__"btshan",
	    "northwest" : "/d/baituo/road3",
	    "westup" : "/d/xingxiu/btyard",
	]));
	set("objects", ([ 
	    CLASS_D("baituo")+"/yin" : 1,
	    "/d/baituo/npc/jiading" : 2,
	]) );
	set("outdoors","xingxiuhai");

	set("cost", 1);
	setup();
}
int valid_leave(object me, string dir)
{
   if (dir =="westup" && me->query("family/family_name")!="����ɽ" ) {
	if (objectp(present("jiading", environment(me))))
		return notify_fail("�Ҷ���ס�����ȥ·����ү���������������������\n");
   }      
   return ::valid_leave(me, dir);
}

