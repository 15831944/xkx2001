//Cracked by Kafei
//Room: /u/yunq/workroom

inherit ROOM;

void create()
{
      set("short", "����С�");
     set("long",@LONG
�����Ǹ�������Դ�����ˡ����������ĵط�����
���������ģ���ֻС���ڻ���ؽ��ţ�������ż�̨
���ԣ��м�������������ҹ��Ϊ����������վŬ���ţ�
һ�źܴ�ĵ�������;��һ�����飨tian shu��,����
�и�·���ɡ�����������վ�Ľ����ָ������������
�����ַ������еĸо�������ؼ���һ����
LONG);
       set("exits", ([
       "qfy" : "/u/qfy/workroom",
     "sdong" : "/u/sdong/workroom",
      ]) );

      set("item_desc", ([
       "shu" : "\n��λ������ָ��,������лл�� \n" 
         ]) );
    set("valid_startroom", 1);
    set("no_fight", "1");

      setup();
       //"/clone/board/yunq_b"->foo();
}
