//Cracked by Kafei
// road: /zhongnan/dong.c

inherit ROOM;

void create()
{
        set("short", "ɽ��");

        set("long",@LONG
����Сɽ�������һ��ǿ���ˮ���Ե����������γ�һ��С������ 
���⡣������ٽ�һ������Ļ����͵�Ҫ����ˮ���ˡ�����ɵ�С�ӱߡ� 
�����ҪǱˮ�ˡ� 
LONG);

		  set("exits",([  "westdown" : __DIR__"water2",
				"out" : __DIR__"river",
							 ])
			  );
		  set("cost",2);

		  setup();
}

int valid_leave(object me, string dir)
{
		  if (  (dir == "westdown")
			  && ( me->query_skill("swimming",1) < 20 )
			  ) {
                  message_vision("��ô����ˮ����������ȥ��ɱѽ��", me);
		  return notify_fail("\n");
		  }
		  return ::valid_leave(me, dir);
}


