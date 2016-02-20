//Change by Server (5/25/2001)
// score.c
// modified by fear@xkx 5-march-2000

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string bar_string = "������������������������";
string blank_string = "������������������������";
string blank_string2 = "                        ";
//string bar_string = "�����������������������";
//string blank_string= "�񩤩�������������������";

string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color);
string tribar_graph2(int val, int eff, int max, string color);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	mapping my;
	string line, str, skill_type;
	object weapon;
	int attack_points, dodge_points, parry_points;

	seteuid(getuid(me));

	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else
		return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

	my = ob->query_entire_dbase();

    line = sprintf("[44;1m[1;33m                  �������и��˵�����(%s����)                       [37;0m\n\n", ob->query("language"),);
	line += sprintf( BOLD " %s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1) );

	line += sprintf(" ����һ%s%s��%s���µ�%s%s��%s����\n",
		ob->query("unit"),
		chinese_number(ob->query("age")), 
		chinese_number(ob->query("month")), 
		ob->query("gender"),
		ob->query("race"),
		CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );

	if( mapp(my["family"]) && my["family"]["master_name"] ) {
		line = sprintf("%s ���ʦ����%s��",
			line, my["family"]["master_name"] );

		if( mapp(my["spouse"])
		&& my["spouse"]["title"] && my["spouse"]["name"] )
			line = sprintf("%s ���%s��%s��\n\n",
				line, my["spouse"]["title"], my["spouse"]["name"] );
		else
			line = sprintf("%s\n\n", line);
	} else {
		if( mapp(my["spouse"])
		&& my["spouse"]["title"] && my["spouse"]["name"] )
		        line = sprintf("%s ���%s��%s��\n\n",
 				line, my["spouse"]["title"], my["spouse"]["name"] );
      else
		line += "\n ";
 	}			

	if( 1 || wizardp(me) || (int)ob->query("age") >= 18 ) {
		line += sprintf(
			" ������[%s/%s] ���ԣ�[%s/%s] ���ǣ�[%s/%s] ����[%s/%s]\n\n", 
			display_attr(my["str"], ob->query_str()),
			display_attr(my["str"], ob->query("str")),
			display_attr(my["int"], ob->query_int()),
			display_attr(my["int"], ob->query("int")),
			display_attr(my["con"], ob->query_con()),
			display_attr(my["con"], ob->query("con")),
			display_attr(my["dex"], ob->query_dex()),
			display_attr(my["dex"], ob->query("dex")));
	}

	if( my["max_jing"] >= my["eff_jing"])
		line += " ��  ��" + tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"]) ) + "\t";
	else
		line += " ��  ��" + tribar_graph2(my["jing"], my["max_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"]) ) + "\t";
	
	if( my["max_jingli"] > 0 )
		line += " ������" + tribar_graph(my["jingli"], my["max_jingli"], my["max_jingli"], status_color(my["jingli"], my["max_jingli"]) ) + "\n";
	else
		line += " ������\n";

	if( my["max_qi"] >= my["eff_qi"])
		line += " ��  ��" + tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"]) ) + "\t";
	else	
		line += " ��  ��" + tribar_graph2(my["qi"], my["max_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"]) ) + "\t";
	
	if( my["max_neili"] > 0 )
		line += " ������" + tribar_graph(my["neili"], my["max_neili"], my["max_neili"], status_color(my["neili"], my["max_neili"]) ) + "\n";
	else
		line += " ������\n";

	if( ob->max_food_capacity() > 0 )
		line += " ʳ�" + tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL) + "\t";
	else
		line += " ʳ�\t";
	
//	line += sprintf(" Ǳ�ܣ� " HIY "%d / %d\n" NOR, ob->query("potential"), ob->query("max_potential") );
	if( my["max_potential"] > 0 )
		line += " Ǳ�ܣ�" + tribar_graph(my["potential"], my["max_potential"], my["max_potential"], GRN) + "\n";
	else
		line += " Ǳ�ܣ�\n";

	if( ob->max_water_capacity() > 0 )
		line += " ��ˮ��" + tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN) + "\t";
	else
		line += " ��ˮ��\t";
		
	line += sprintf(" ���飺 " HIM "%d\n" NOR, ob->query("combat_exp") );

	line += sprintf(" ��  �� " HIR "%10d            \t" NOR, ob->query("shen") );
	line += sprintf(" ������ " HIC "%d           " NOR, ob->query("quest_exp") );
//	line += sprintf(" ��£�     " HIR "%d\n" NOR, ob->query("behavior_exp") );

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "kick";

	if (wizardp(me))
	line += sprintf("\n ������: " HIW "%d (+%d)" NOR "\t\t �������� " HIW "%d (+%d)\n" NOR,
		attack_points/100 + 1, ob->query_temp("apply/damage"),
		(dodge_points + (weapon? parry_points: (parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));
	else line += "\n";

	line += sprintf("\n �㵽ĿǰΪֹ�ܹ�ɱ�� %d ���ˣ������� %d ����������ҡ�",
		my["MKS"] + my["PKS"], my["PKS"]);
	line += sprintf("\n �㵽ĿǰΪֹ�ܹ����� %d �Σ����� %d �������������� \n\n", 
		my["death_count"], my["death_times"] );

	write(line);
	return 1;
}

string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf( HIY "%3d" NOR, value );
	else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
	else return sprintf("%3d", value);
}

string status_color(int current, int max)
{
	int percent;

	if( max ) percent = current * 100 / max;
	else percent = 100;

	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}

string tribar_graph(int val, int eff, int max, string color)
{
	return color + bar_string[0..(val*12/max)*2-1]
		+ ((eff > val) ? blank_string[(val*12/max)*2..(eff*12/max)*2-1] : "") + NOR;
}

string tribar_graph2(int val, int eff, int max, string color)
{
	return color + bar_string[0..(val*12/max)*2-1]
		+ ((eff > val) ? blank_string2[(val*12/max)*2..(eff*12/max)*2-1] : "") + NOR;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : score
           score <��������>                   (��ʦר��)

���ָ�������ʾ��(��)��ָ������(������)�Ļ������ϡ�

see also : hp
HELP
    );
    return 1;
}

//�������ϵ��趨����� 'help setup'��

