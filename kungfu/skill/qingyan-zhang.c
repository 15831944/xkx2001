//Cracked by Roath
// qingyan-zhang.c ����������
//cyz
inherit SKILL;

mapping *action = ({
([	"action" : 
"$N˫�Ʊ�����£�һʽ����������������$n��$l",
	"force" : 90,
        "dodge" : 5,
        "parry" : 20,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : 
"$N����΢�࣬����һʽ���������ơ�������ˮ�����бб�ĳ�",
	"force" : 140,
        "dodge" : 10,
        "parry" : 15,
	"damage": 20,
	"lvl" : 10,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : 
"$N˫��������������$n��$l�������Ʒ�֮�£�һʽ���̺����Ρ���$n��ȥ",
	"force" : 180,
        "dodge" : 15,
        "parry" : 20,
	"damage": 30,
	"lvl" : 20,
	"skill_name" : "�̺�����",
        "damage_type" : "����"
]),
([      "action" :   
"$Nһʽ���������졹����ɫһƬ�԰ף�˫�ƻó������ѩ��������$n����",
        "force" : 210,
        "dodge" : 15,
        "parry" : 25,
        "damage": 35,
        "lvl" : 30,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" :   
"$N���λζ����ó�������ӰΧ����$n���ߣ������ĳ�һ��������������һʽ������������",
        "force" : 260,
        "dodge" : 15,
        "parry" : 25,
        "damage": 50,
        "lvl" : 40,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" :
"$N˫��һ����һʽ��������ɢ���������$n�Ļ����;ƴ�������һ�",
       
	"force" : 420,
        "dodge" : 40,
        "parry" : 30,
	"damage": 60,
	"lvl" : 50,
	"skill_name" : "������ɢ",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jinyu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����������Ʊ�����֡�\n");
	if ((int)me->query_skill("kurong-changong", 1) < 20
		&& (int)me->query_skill("beiming-shengong", 1) < 20)
	return notify_fail("��Ŀ���������򲻹����޷�ѧ���������ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷������������ơ�\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("qingyan-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("����������������������ơ�\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -5);
	return 1;
}

