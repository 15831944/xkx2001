//Cracked by Roath
// more.c

#include <ansi.h>

void more(string cmd, string *text, int line)
{
	int i,j;

	switch(cmd) {
		case "":
		case "n":
			for(i=line + 23; line<sizeof(text) && line<i; line++)
				write(text[line] + "\n");
			if( line>=sizeof(text) ) return;
			break;
	case "b":
	line = line - 46;
	if(line<-22) return;
	for(i=line + 23; line < i;line++)
		write(text[line]+"\n");
	break;
		case "q":
			return;
	}
	printf("== δ����� " HIY "%d%%" NOR " == (n �� <ENTER> ������һҳ��q �뿪��b ǰһҳ)",
		(line*100/sizeof(text)) );
	input_to("more", text, line);
}

void start_more(string msg)
{
	more("", explode(msg, "\n"), 0);
}
