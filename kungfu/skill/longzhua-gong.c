//Cracked by Roath
// longzhua-gong.c -��צ��
// maco 7/9

inherit SKILL;
#include <combat.h>
#include <ansi.h>

int next_hit(object me, object victim, object weapon, int damage);

mapping *action = ({
([      "action" : "$N˫����������϶���ͬץ��ʹһ�С�����ʽ����Ѹ��֮����ֱ����$n����̫��Ѩ",
        "force" : 120,
        "dodge" : 5,
        "lvl"   : 0,
        "skill_name" : "����ʽ" ,
        "post_action": (: next_hit :),  
        "damage_type" : "����"
]),
([      "action" : "$N˫��һ��Ȧת��ʹ�С�����ʽ��������ٿ������������$n���ԡ��縮Ѩ��",
        "force" : 130,
        "dodge" : 5,
        "damage": 5,
        "lvl"   : 6,
        "skill_name" : "����ʽ" ,   
        "post_action": (: next_hit :),
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��һ�С�����ʽ����������̽������Ю��һ�ɾ��磬ֱ����$n��硰ȱ��Ѩ��",
        "force" : 150,
        "dodge" : 10,
        "damage": 5,
        "lvl"   : 12,
        "skill_name" : "����ʽ" ,       
        "post_action": (: next_hit :),  
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ�С�����ʽ����������ָ��$n��$l��ץ���£��ַ�������Ѹ�汸���Ƶ�����֮��",
        "force" : 180,
        "dodge" : 10,
        "damage": 10,
        "lvl"   : 18,
        "skill_name" : "����ʽ" ,     
        "post_action": (: next_hit :),
        "damage_type" : "ץ��"
]),
([      "action" : "$N�͵��������һ�С�׽Ӱʽ����$n�˽��������ý�Ѹ�ݣ����ƷǷ�",
        "force" : 220,
        "dodge" : 15,
        "damage": 10,
        "lvl"   : 24,
        "skill_name" : "׽Ӱʽ" ,               
        "post_action": (: next_hit :),
        "damage_type" : "ץ��"
]),
([      "action" : "��������һ�죬$N�ұۼ����������ָ΢΢���²�����һ�С�����ʽ��ץ��$n��$l",
        "force" : 260,
        "dodge" : 15,
        "damage": 15,
        "lvl"   : 30,
        "skill_name" : "����ʽ" ,               
        "post_action": (: next_hit :),
        "damage_type" : "ץ��"
]),
([      "action" : "$N���������������ڻӣ���Ȼ��Ϊһ�С���ɪʽ��ץ��$n$l������������ٱ",
        "force" : 300,
        "dodge" : 25,
        "damage": 20,
        "lvl"   : 45,
        "skill_name" : "��ɪʽ" ,               
        "post_action": (: next_hit :),
        "damage_type" : "ץ��"
]),
([      "action" : "$N˫�֡�����ʽ������������������Ӱ�ɿգ�˫צ���裬˲Ϣ֮�䣬�ѽ�$nѹ�Ƶ��޴�����",
        "force" : 350,
        "dodge" : 25,
        "damage": 25,
        "lvl"   : 50,
        "skill_name" : "����ʽ" ,               
        "post_action": (: next_hit :),
        "damage_type" : "ץ��"
]),
([      "action" : "$N̤�ϼ���������һ�С�����ʽ����������$n$lץ����������һץ������ָ��ñ�ֱ�����������Ѽ�",
        "force" : 400,
        "dodge" : 30,
        "damage": 25,
        "lvl"   : 55,
        "skill_name" : "����ʽ" ,               
        "post_action": (: next_hit :),
        "damage_type" : "ץ��"
]),
([      "action" : "$N����һ������������ʵ����������׾��������ʽ��������ɽ��ʹ������",
        "force" : 460,
        "dodge" : 40,
        "damage": 30,
        "lvl"   : 60,
        "skill_name" : "����ʽ" ,       
        "post_action": (: next_hit :),
        "damage_type" : "ץ��"
]),
([      "action" : "$Nһ��ԭ�ȸ���·�ӣ���������ȱʽ����צ·�����а������ᣬʵ�ѵ��˷�豹��棬¯����ľ���",
        "force" : 520,
        "dodge" : 40,
        "damage": 50,
        "lvl"   : 70,
        "skill_name" : "��ȱʽ" ,
        "post_action": (: next_hit :),
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="qianye-shou"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����צ��������֡�\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
                return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ��צ����\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷�����צ����\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}


mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("longzhua-gong",1);

        if( me->query_temp("lzg_lianhuan"))
        {
	return action[me->query_temp("lzg_lianhuan")-1];
        }

		else {
	for(i = sizeof(action); i > 0; i--) 

	if(level > action[i-1]["lvl"])
                return action[NewRandom(i, 20, level/5)];
	}
}


int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("���������������צ����\n");

        if( (int)me->query_skill("banruo-zhang", 1) < 180 )
                return notify_fail("��İ�������Ϊ��������\n");

        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

int next_hit(object me, object victim, object weapon, int damage)
{
        string *msg;
        msg = ({
                HIR"\n$Nһץ���У���ץ���������Ƹ���Ѹ�ݸ��ͣ�" NOR,
                HIR"\n$N��צ��ԴԴ������һ����գ��ּ�����������" NOR,
                HIR"\n$n�Ŷ�����У�$N����������ץ���켫�ݼ���"NOR,
        });

        if(damage==RESULT_DODGE 
        && (int)me->query_skill("longzhua-gong",1) > 100 
        && 2>random(3)
        && !me->query_temp("lzg_lianhuan")
        && !me->query_temp("next_hit")) {
        message_vision(msg[random(sizeof(msg))] , me,victim );
        me->add("neili", -20);
        me->add_temp("next_hit",1);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        me->delete_temp("next_hit");
        }
        
}

string perform_action_file(string action)
{
                return __DIR__"longzhua-gong/" + action;
}
