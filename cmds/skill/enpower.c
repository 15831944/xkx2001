//Cracked by Roath
// enpower.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts;

	if( !arg || (arg!="basic" && !sscanf(arg, "%d", pts)) ) 
		return notify_fail("ָ���ʽ��enpower|jiajin <ʹ�����������˵�>|basic\n");

	if( arg=="basic" )
		me->set("jiajin", 1);
	else {
		if( pts < 1 || pts > (int)me->query("max_jingli")/20 )
			return notify_fail("��ֻ���� basic ��ʾֻ��һ�������������ֱ�ʾÿһ���ü����������Ҳ��ܳ����������ֵ��\n");
		me->set("jiajin", pts);
	}

	write("�趨��ϡ�\n");
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: enpower|jiajin <ʹ�����������˵�>|basic
 
���ָ������ָ��ÿ�λ��е���ʱ��Ҫ�������������˵С�

enpower baisc ���ʾ��ֻ��һ�������� 

HELP
        );
        return 1;
}
