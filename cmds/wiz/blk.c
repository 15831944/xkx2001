// Change by Server
// blkbot.c

inherit F_CLEAN_UP;


int main(object me, string str)
{
	object ob;
	int i;
	if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("��... ���������?\n");
	// moving
	tell_room(environment(ob),"��������һֻ���ְ�"+
	(string)ob->query("name")+"ץ������, Ȼ�᲻����.\n", ob);
	tell_object(ob,"һֻ�ְ���ץ������, ����ǰһ���....\n");
	ob->move("/d/death/blkbot");
        tell_object(me, "���"+(string)ob->query("name")+"����շ��䡣\n");
	tell_object(ob,".... ����ʱ������"+(string)me->query("name")+
	"����Ū������.\n");
	tell_room(environment(ob),(string)ob->query("name")+"ͻȻ����"+
	"������ǰ\n",({me,ob}));
	// ok ..
	log_file("static/BLK", sprintf("[%s]%s(%s)��%s(%s)�ͽ��շ��䡣\n",
                ctime(time())[0..15], ob->name(), geteuid(ob), me->name(), geteuid(me)));
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : blk <ĳ��>

��ָ�������(��)��ĳ�˹ص��շ�����ȥ��
HELP
    );

    return 1;
}
