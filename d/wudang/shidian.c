//Cracked by Roath
// shidian.c ʯ�� 
// xQin 11/00

inherit ROOM;
#include <room.h>
string look_shiliang();

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���������ϵ�ʯ��ͽ��������ͱ��ϣ���������Ƕ��ǧ������֮�䡣
ʯ���Ͻ����죬���پ����������һ�Ϊһ�壬ʹ����Ϊ����񹦡�ʯ���
�������һ����ʯ����shiliang�������������塣��ͷ����С��¯����ȥ��
�������ð������Σ����ȥ���㣬�׳Ƶ���ʯ��Ϊ����ͷ�㡱��
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"nanyan",
	]));
	
	set("item_desc", ([
		"shiliang" : "
������ȥ��ֻ��ʯ������һ�ɣ����һ�ߣ��ڿ����ɡ����Ṧ����Ҳ��Ծ��һ��
(jump shiliang)������ʯ�����ƺ�ֻ������һ�ˡ�\n",
	]));

	set("cost", 6);
	setup();
}
void init()
{
        add_action("do_mianbi","���");
        add_action("do_mianbi","mianbi");
        add_action("do_jump", "jump");
}

int do_mianbi()
{
        object me, mengzhu, room;
        int shen, ep, gain;
        me = this_player();
        shen = me->query("shen");
        ep = me->query("combat_exp");

        if (me->is_busy()
        || me->query_temp("pending/exercising")
        || me->query_temp("exit_blocked"))
                return notify_fail("��������æ���ء�\n");

        if (me->query("jing") < 200 || me->query("jingli") < 200)
        return notify_fail("����÷��겻�������Ծ۾��붨��\n");
        
        message_vision("$N�����ʯ��������˼�����ã���������\n", me);

        me->start_busy(8);
        me->set("jing",1);
        me->add("jingli", -200);

        if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");
        seteuid(getuid(me));
        if( !objectp(mengzhu = present("mengzhu", room)) ){
        mengzhu = new("/clone/npc/meng-zhu");
        mengzhu->move("/d/taishan/fengchan");
        }

        if (userp(me) && me->query("id") != mengzhu->query("winner") ){
        if (shen > 10000 && shen > ep){
        gain = (shen - ep) * 1000 / ep; 

        if (gain > 20) gain = 20;

        if (me->query("family/family_name") != "�䵱��") gain = gain/4;

        me->add("combat_exp", gain * 8 + random(gain*4));
        me->set("shen", me->query("combat_exp"));

        if (me->query("family/family_name") == "�䵱��")
        me->add("potential", gain * me->query_skill("taoism") / 25
        + random(gain*me->query_skill("taoism")/60));

        if (me->query("potential") > me->query("max_potential"))
        me->set("potential", me->query("max_potential"));
        }
    }
        return 1;
}

int do_jump(string arg)
{
	object room;
	object me;
	int lv, cost;
	me=this_player();
	

        
	if (!arg || arg != "shiliang" ) return notify_fail("��Ҫ�������\n");
	
	cost = (me->query_dex()*me->query_skill("dodge")/ me->query_con() )/10;
        if (cost < 10) cost= 10;
        if( me->query("jingli") < 30)
        return notify_fail("���Ѿ���ƣ�����ˡ�\n");
        
        lv = me->query("int", 1)*2;
	if (me->query_skill("dodge") > 200) lv /=2;
	if (me->query_skill("dodge") > 300) lv /=3;
	if (me->query_skill("dodge") > 400) lv /=4;
	if (me->query_skill("dodge") > 500) lv /=5;
	
	if (me->query_skill("dodge", 1) < 20)
	return notify_fail("���Ṧ�������˾ٶ�����ɱ���ɡ�\n");
	
	if (me->query_skill("dodge", 1) < 100 && random(150)==1)
	{
	me->add("jingli", -cost);
	message_vision("$Nһ���������ʯ����ֻ����Ծ����ʯ��ʱ����ͻȻ��ֱ��ˤ����Ԩ��\n", me);
	
	me->move(__DIR__"shijie1"); 
	tell_object(me,"��ֻ�����������磬���ϵ�����׹���Ա��ŵĲ������ҡ�\n");
	message("vision", "ֻ���á��项��һ�����죬" +me->name() 
			+"ײ��ʯ���ϣ�ˤ�÷�����ǣ�����һ���⽬��\n", environment(me), me);
	me->set_temp("last_damage_from", "������ʯ��ˤ����");
	me->receive_wound("qi", me->query("max_qi")+100);
	return 1;
	}
	if( !(room = find_object(__DIR__"long_shiliang")) )
        room = load_object(__DIR__"long_shiliang");
        
        if( room = find_object(__DIR__"long_shiliang") )
        if((int)room->query_temp("shiliang_trigger")==1 )
        {
        message_vision("$Nһ���������ʯ��������������������Ȼ$N�ַ��˻�������������ʧ�롣", me) ;
        me -> move( __DIR__"long_shiliang");
        me -> move( __DIR__"shidian");
        me->add("jingli", -cost);  
        me->start_busy( 1 );
        me->improve_skill("dodge", lv+random(lv) );
        tell_object(me,"ԭ������ͻȻ�����и���Ӱ����ʯ���ϣ��������ǣ�����\n"
                       "Ӳ����һ���������˻�����");
       return 1 ;
    }
    room->set_temp("shiliang_trigger", 1);
    message_vision("$N����ʩչ�Ṧ��һ����Ծ����ʯ����\n", me );
    me->move(room) ;
    me->improve_skill("dodge", lv+random(lv) );
    me->add("jingli", -cost);  
    tell_object(me,"\n������һ������������Ծ����ʯ������Լ������һԾ���Լ����Ṧ����������\n"  ) ;
    room->delete_temp("shiliang_trigger");
    me->start_busy( 1 );
    return 1 ;
}
	