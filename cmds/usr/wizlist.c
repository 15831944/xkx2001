// Change by Server
// wizlist.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *list;
	mapping wizstatus;
	int j = 0;
	int i; 
	write(MUD_NAME + "Ŀǰ����ʦ�У�");

//
//	for(int i=0; i<sizeof(list); i++)
//		printf("%-15s%c", list[i],  (i%5==4) ? '\n' : ' ');

	wizstatus = SECURITY_D->query_wizstatus();
	list = keys(wizstatus);

/*	write(HIW"\n\n����ۡ�  "NOR);
	for(int i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(admin)" )
		{
			j++;
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
		}
	}
*/
	j=0;
	write(HIY"\n\n������  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(arch)" )
		{
			j++;
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
		}
	}

	j=0;
	write(HIG"\n�����ɡ�  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(wizard)" )
		{
			j++;
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
		}
	}

	j=0;
        write(HIM"\n��ɢ�ɡ�  "NOR);
        for( i=0; i<sizeof(list); i++)
        {
                if( wizstatus[list[i]] == "(virtuoso)" )
                {
                        j++;
                        printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
                }
        }

	j=0;
	write(YEL"\n����١�  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(caretaker)" )
		{
			j++;
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
		}
	}

	j=0;
	write(GRN"\n����ʦ��  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(designer)" )
		{
			j++;
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
		}
	}

	j=0;
	write(HIC"\n�����ɡ�  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(creator)" )
		{
			j++;
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
		}
	}

	j=0;
	write(MAG"\n�����ˡ�  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(apprentice)" )
		{
			j++;
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
		}
	}


	j=0;
	write(CYN"\n�����ɡ�  "NOR); 	for(i=0; i<sizeof(list); i++) 	{ 		if( wizstatus[list[i]] == "(immortal)" ) 		{ 			j++; 			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' '); 			if(j==7)break; 		} 	}  	write(CYN"�����ɡ�  "NOR); 	for(; i<sizeof(list); i++) 	{ 		if( wizstatus[list[i]] == "(immortal)" ) 		{ 			j++; 			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' '); 			if(j==7)break; 		} 	} 


	write("\n\n");
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : wizlist

��; : �г�Ŀǰ���е���ʦ������
HELP
     );
     return 1;
}
