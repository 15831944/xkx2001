//Cracked by Roath
// shout.c

inherit F_CLEAN_UP;

#define SHOUT_LIST	({ })
int main(object me, string arg)
{
//	if( !wizardp(me) && me->query("id") != "sad" &&
//	me->query("id") != "long" )
	if (!wizardp(me) && member_array(me->query("id"), SHOUT_LIST) == -1)
		return notify_fail("Ŀǰ�ݲ�������� shout��\n");
	if (!arg) return notify_fail("����Ҫ���ʲô��\n");
	shout( me->name() + "������Х��" + arg + "\n");
	write("��������Х��" + arg + "\n");
	return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : shout <ѶϢ>
 
���ָ�����㽫 <ѶϢ> ���ͳ�ȥ, ����������Ϸ�е��˶�
��������Ļ�.
 
see also : tune
HELP
    );
    return 1;
}
 
