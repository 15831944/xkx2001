//Cracked by Kafei
// edit.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file)
{
	if( !file ) return notify_fail("ָ���ʽ��edit <����>\n");
/*
	if( me->query("id") != "server" 
		&& me->query("id") != "xuanyuan"
		&& me->query("id") != "lbc"
		&& me->query("id") != "liu"
		&& me->query("id") != "linglong"
		&& me->query("id") != "lax") 
	return notify_fail("��û���޸����������Ȩ��\n");
*/
	if( in_edit(me) ) return notify_fail("���Ѿ���ʹ�ñ༭���ˡ�\n");

	seteuid(geteuid(me));
	ed(resolve_path(me->query("cwd"), file));
        log_file("static/editfile", sprintf("%s%s edit %s (%s)\n",
                me->query("name"),
                "(" + me->query("id") + ")" ,
                resolve_path(me->query("cwd"), file),
                ctime(time())
                ) );
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : edit <����>, edit here

���ô�һָ���ֱ�������ϱ༭������
HELP
    );
    return 1;
}
