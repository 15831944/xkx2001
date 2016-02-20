//Cracked by Roath
// cp.c
// modified for more security, sdong, 11/15/98

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string src, dst, *dirs;
	string file;
	object ob;

	seteuid(geteuid(me));
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
		notify_fail("ָ���ʽ: cp <ԭ����> <Ŀ�굵��> \n");

	src = resolve_path(me->query("cwd"), src);
	dst = resolve_path(me->query("cwd"), dst);

	if( file_size(src) < 0 ) {
		ob = present(src, me);
		if( !ob ) ob = present(src, environment(me));
		if( !ob ) return notify_fail("û�����������\n");
		file = base_name(ob) + ".c";
	}

	if(!SECURITY_D-> valid_read(src, this_object(), "read_file") && me->query("id") != "sdong" )return notify_fail("�Բ�����û��COPY���������Ȩ����\n");

	if( file_size(dst)==-2 ) {
		dirs = explode(src, "/");
		dst += "/" + dirs[sizeof(dirs)-1];
	}

	if( cp(src, dst) )
		write("Ok.\n");
	else
		write("��û���㹻�Ķ�дȨ����\n");
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : cp <ԭ����> <Ŀ�굵��>

��ָ�������(��)����������
HELP
	 );
	 return 1;
}
 
