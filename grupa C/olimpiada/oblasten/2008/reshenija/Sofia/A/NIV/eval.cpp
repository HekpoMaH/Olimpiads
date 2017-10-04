#include <stdio.h>
#include <string.h>
inline bool _ISOP(char op)
{
 return (op=='+'||op=='-'||op=='*'||op=='/'||op=='^');
}
int Factor;
int Recurs;
int Result=0;
char Buff[26];
char plfl=0;
char opp='\0';
int main()
{
    start:
    Factor=1;
    Result=0;
    plfl=0;
    opp='\0';    
    scanf("%25s",Buff);
    printf("%s",Buff);
    for(int i=0;i<strlen(Buff);i++)
    {
    if(Buff[i]=='(')
    {
     Recurs++;
     if(i>=2&&Buff[i-2]==')')
     Factor*=2;
    }
    if(Buff[i]==')')
    {
     int k=i;
     Recurs--;
     k++;
     opp=Buff[k];
     if(opp=='+' && plfl)
     Result += 1*Factor;
     if(_ISOP(opp))
     {
      plfl = opp=='+';
     }
     k++;
     if(Buff[i]!='(')
     Result += 1*Factor;
     k--;
    }
    opp=Buff[i];
     if(opp=='+' && plfl)
     Result += 1*Factor;
     if(_ISOP(opp))
     {
      plfl = opp=='+';
     }
    }
    printf("%d\n",Factor);
    return 0;
}
