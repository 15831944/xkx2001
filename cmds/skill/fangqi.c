//Cracked by Roath
// abandon.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping skills, skillmap;
	string *skill;
	int i;
	
	if( !arg || arg=="" ) 
		return notify_fail("��Ҫ������һ��ܣ�\n");

	if( !me->delete_skill(arg) )
		return notify_fail("�㲢û��ѧ������ܡ�\n");

	write("�������������ѧϰ" + to_chinese(arg) + "��\n");

	if( arg =="all" ) {
		skills = me->query_skills();
		if( !mapp(skills) || sizeof(skills)==0 ) return 1;

		skill = keys(skills);
		for (i=0; i<sizeof(skill); i++) {
			me->delete_skill(skill[i]);
		}
	} else {		 
		skillmap = me->query_skill_map();
		if( !mapp(skillmap) || sizeof(skillmap)==0 ) return 1;

		skill = keys(skillmap);
		for (i=0; i<sizeof(skill); i++) {
			if( skillmap[skill[i]] == arg ) me->map_skill(skill[i]);
		}
	}
	
	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��abandon|fangqi <��������>

����һ������ѧ���ļ��ܣ�ע��������˵�ġ���������ָ������ܴ�������
��������ɾ����������Ժ�Ҫ��������ӣ���ʼ����������ؿ��������

���ָ��ʹ�õĳ���ͨ��������ɾ��һЩ����С�ġ��������ļ��ܣ�����ÿ��
�����Ų�ͬ���츳������ϰ���书Ҳ������ͬ�����������ѧ����ͷ��ֻ����
��������
TEXT
	);
	return 1;
}
