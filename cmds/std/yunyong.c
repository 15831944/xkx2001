//Cracked by Roath
// /cmds/war/trick.c
// by jun@SIA

#include "/tmp/mpfight/war_include/war_temp.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string file, target, jimou;
    
    seteuid(getuid());
    
    if( !me->query_temp("war/war")) return notify_fail("�㲢�����ڴ��̣�\n");
    
    if( me->query_temp("in_war/is_hunluan") ) 
        return notify_fail("��ľ���̫�����ˣ���û�а취ʹ�ü�ı��\n");

    if( me->is_busy() )
	return notify_fail("����æ�ڱ�������ء�\n");

    if( me->query_temp("in_war/trick_amount") == 0)
        return notify_fail("���Ѿ����ɲž���ǭ¿�����ˡ�����\n");

    if( me->query_temp("in_war/is_tricking") )
    	return notify_fail("���Ѿ���ʹ�ü�ı�ˡ�\n");

    if(sizeof(all_inventory(environment(me))) > 1 ) 
        return notify_fail("��ľ������ڴ����ء�\n");
        	
    if( !arg ) return notify_fail("��Ҫ��ʲô��ı����\n");
    
    if( sscanf(arg, "%s %s", jimou, target)==2 ) {}
    else jimou = arg;         
    	
    if( !stringp(file = TRICK_D(jimou) ) 
	|| file_size(file + ".c") <= 0 )
	    return notify_fail("û�����ּ�ı��\n");
    return (int)call_other( TRICK_D(jimou), "trick", me, target);
}

int help (object me)
{
// later maybe add ���� - ָ���ʽ��trick <��ı����> [<ʩ�ö���>]
    write(@HELP
������ս�����ü�ı��ָ�
ָ���ʽ��  tricky <��ı����>
	or  tricky <��ı����> <ʩ�ö���>
	or  tricky <��ı����> <����>

    �磺tricky fire	ʹ�û�ơ�
        tricky recover or tricky recover <id>	
HELP);
    return 1;
}
