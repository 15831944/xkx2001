//Cracked by Kafei
// meinu-quan.c ��Ůȭ��
// shizika 8/5/97

inherit SKILL;

mapping *action = ({
([	"action" : "$N����һ̽��һ�С��������¡�����$n��ͷ���˹�ȥ��ֱ��$n��$lն��",
	"force" : 380,
	"dodge" : 30,
      "parry" : 30, 
	"lvl" : 80,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : "$Nһ�С���ʩ���ġ���˫������һȦ����ȭ��׼$n���Ŀ�ֱ������",
        "force" : 400,
        "dodge" : 15,
        "parry" : 40,
	  "lvl" : 90,
        "skill_name" : "��ʩ����",
        "damage_type" : "����"
]),
([      "action" : "$N���������õ����ƣ�����б�٣�������ָ����һ�С��Ѿ�������������ָ��$n��$l��ȥ",
        "force" : 360,
        "dodge" : 25,
        "parry" : 30,
	  "lvl" : 75,
        "skill_name" : "�Ѿ�����",
        "damage_type" : "����"
]),
([      "action" : "$N����һ����һ�С�������١�˫�ֺ�ȭ����̧��$n��$l",
        "force" : 300,
        "dodge" : 15,
        "parry" : 10,
        "lvl" : 70,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N���ֻ����������ң���������֯��״��һ�С�����֯������һ��һ�ͼ䣬˫�ַֻ�$n��$l",
        "force" : 320,
        "dodge" : 10,
        "parry" : -10,        
	  "lvl" : 68,
        "skill_name" : "����֯��",
        "damage_type" : "����"
]),
([      "action" : "$N�������������֮״��һ�С��ľ����䡹����$n��$lһ��",
        "force" : 270,
        "dodge" : 20,
        "lvl" : 50,
        "skill_name" : "�ľ�����",
        "damage_type" : "����"
]),
([      "action" : "$N����ҡ�Σ�����ײײ��������б��ȥ��һ�ǡ�������ơ���ͷ��$n��$lײȥ",
        "force" : 350,
        "dodge" : 35,
        "lvl" : 85,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N����������ǰ�����ֿ��ճ�ȭһ�С�Ū��������²��$n��$l",
        "force" : 200,
        "parry" : -10,
        "lvl" : 20,
        "skill_name" : "Ū����",
        "damage_type" : "����"
]),
([      "action" : "$N����Ʈ�ݣ����������ѩ��ӭ��$n�Ĺ���ƮȻ����������һʽ�������貨��",
        "force" : 320,
        "dodge" : 25,
        "lvl" : 65,
        "skill_name" : "�����貨",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С���߮��ȭ��˫ȭ�������ʣ���ǰƽ�ƶ���������$n��$l",
        "force" : 200,
        "dodge" : 15,
        "lvl" : 40,
        "skill_name" : "��߮��ȭ",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ�����촹����������ǰ�ˣ�˫���Դ���ʽ��$n��$lֱ������",
	"force" : 280,
	"dodge" : 30,
        "lvl" : 55,
	"skill_name" : "���촹��",
        "damage_type" : "����"
]),
([	"action" : "$Nһ�С�������ġ�������ǰ��˫�۽�����$n��$l�����ȥ",
	"force" : 150,
	"dodge" : 25,
        "lvl" : 30,
	"skill_name" : "�������",
        "damage_type" : "����"
]),
([	"action" : "$NͻȻ���䲻���ߵ��ֱ�룬һ�ǡ����ҹ�������˴�ȭ��$nֱ�����",
	"force" : 180,
	"dodge" : 20,
        "lvl" : 25,
	"skill_name" : "���ҹ��",
        "damage_type" : "����"
]),
([	"action" : "$N�������¸��壬һʽ������׹¥���˵���$n�����̹�ȥ",
	"force" : 190,
	"dodge" : 15,
        "lvl" : 20,
	"skill_name" : "����׹¥",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��ļ��麺��˫���������£������Ƴ����࣬��ס$n��ȫ��",
        "force" : 270,
        "parry" : 20,
        "lvl" : 45,
        "skill_name" : "�ļ��麺",
        "damage_type" : "����"
]),
([      "action" : "$N����������״�����������ӣ�һ�С����ߵ��С�����$n��$l",
        "force" : 130,
        "dodge" : 10,
        "lvl" : 15,
        "skill_name" : "���ߵ���",
        "damage_type" : "ץ��"
]),
([      "action" : "$N��ǰ���һ��������һ�С�ľ���乭�������ֺ��������ּ���ǰ����$n��$l",
        "force" : 250,
        "parry" : 15,
        "lvl" : 35,
        "skill_name" : "ľ���乭",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ���༧��ʫ��˫�����������״������̧�ֻ���$n���ظ���ͬʱ������ǰƮ��",
        "force" : 100,
        "parry" : -10,
        "lvl" : 10,
        "skill_name" : "�༧��ʫ",
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ�С��϶���ҩ��������ƮƮ��˫�ֽ�������$n��$l",
        "force" : 300,
        "paryy" : 20,
        "lvl" : 64,
        "skill_name" : "�϶���ҩ",
        "damage_type" : "����"
]),
([      "action" : "$N��֫��ڣ����Ϻ������֮����һʽ���������ˡ������в��ƻ���$n��$l",
        "force" : 50,
        "dodge" : 60,
        "lvl" : 37,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N΢΢һЦ����ָ�ſ���������ͷ����һ�ᣬ˳�ƻ���$n��$l��ȴ��һ�С�������ױ��",
        "force" : 150,
        "dodge" : 10,
        "lvl" : 0,
        "skill_name" : "������ױ",
        "damage_type" : "����"
]),
([      "action" : "$N����һ��һ����һ�С�Ƽ�����񡹣���ָ����$n��$l",
        "force" : 160,
        "dodge" : 5,
        "lvl" : 5,
        "skill_name" : "Ƽ������",
        "damage_type" : "����"
]),
([      "action" : "$Nͻʹһ�С������ǡ����������Լ���ǰ����������$n��$l",
        "force" : 80,
        "parry" : 70,
        "lvl" : 18,
        "skill_name" : "������",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="tianluo-diwang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ůȭ��������֡�\n");
	if ((int)me->query_skill("yunu-xinjing", 1) < 20)
		return notify_fail("�����Ů�ľ���򲻹����޷�ѧ��Ůȭ����\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����Ůȭ����\n");
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
        level  = (int)me->query_skill("meinu-quan", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("���������������Ůȭ��\n");
        me->receive_damage("jingli", 25, "����͸֧�������ˡ�");
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"meinu-quan/" + action;
}
