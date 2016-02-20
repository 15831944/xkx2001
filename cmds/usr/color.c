// Change by Server
// color.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
//int i;
	string cn;

	if( me->query("combat_exp") < 500000)
		return notify_fail("�������������������û���ʸ���ɫ��\n");
	cn = me->query("colorname");
	if( cn &&  cn[7..strlen(cn)-8] == me->query("name"))
		return notify_fail("��������Ѿ�����ɫ�ˡ�\n");

	if( !arg ) return notify_fail("��Ҫ���Լ���������ʲôɫ��\n");

	if( arg == "RED") me->set_color("$RED$");
	if( arg == "GRN") me->set_color("$GRN$");
	if( arg == "YEL") me->set_color("$YEL$");
	if( arg == "BLU") me->set_color("$BLU$");
	if( arg == "MAG") me->set_color("$MAG$");
	if( arg == "CYN") me->set_color("$CYN$");
	if( arg == "WHT") me->set_color("$WHT$");
	if( arg == "HIR") me->set_color("$HIR$");
	if( arg == "HIG") me->set_color("$HIG$");
	if( arg == "HIY") me->set_color("$HIY$");
	if( arg == "HIB") me->set_color("$HIB$");
	if( arg == "HIM") me->set_color("$HIM$");
	if( arg == "HIC") me->set_color("$HIC$");
	if( arg == "HIW") me->set_color("$HIW$");

	else if(!me->query("colorname"))
	return notify_fail("��Ҫ���Լ���������ʲôɫ��\n");

	write("�����������Ư�����ˡ�\n");
	return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : color <��ɫ>
 
���������ʮ���飬��ô����Ը����Լ����������ּ���һ����ɫ��
��ѡ��������ɫ��
��ע�⣡������ɫһ�����ϾͲ��ܸ��ģ���������������֣�������

RED - ��ɫ		HIR - ����ɫ
GRN - ��ɫ		HIG - ����ɫ
YEL - ����ɫ		HIY - ��ɫ
BLU - ����ɫ		HIB - ��ɫ
MAG - ǳ��ɫ		HIM - �ۺ�ɫ
CYN - ����ɫ		HIC - ����ɫ
WHT - ǳ��ɫ		HIW - ��ɫ

HELP
        );
        return 1;
}
