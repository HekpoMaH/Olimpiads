#include<stdio.h>

    char s[27];
    char znaci[25];

int main()
{
    int i, j;
    long otg = 1, br = 1;
    
    gets(s);
    
    for(i = 0, j = 0; i <= strlen(s); i++)
    {
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '^' || s[i] == '/' || s[i] == '(' || s[i] == ')') {znaci[j] = s[i]; j++;}
    }
    znaci[j] = '\0';

    for(i = 0; i <= strlen(znaci); i++)
    {
        if(znaci[i] == '+')
        {
                for(j = i+1; j <  strlen(znaci); j++, i++)
                {
                        if(znaci[j] == '+') br++;
                        if(znaci[j] == '-') {br++; if(znaci[j+1] == '-') break;}
                        if(znaci[j] != '+' && znaci[j] != '-') break;
                }
        }

        otg = otg*br;
        br = 1;
        
        if(znaci[i] == '*')
        {
                for(j = i+1; j <  strlen(znaci); j++, i++)
                {
                        if(znaci[j] == '*') br++;
                        if(znaci[j] == '/') {br++; if(znaci[j+1] == '/') break;}
                        if(znaci[j] != '*' && znaci[j] != '/') break;
                }
        }

        otg = otg*br;
        br = 1;
        
        if(i != 0 && i != strlen(znaci))
        {
                if(znaci[i-1] == ')' && znaci[i+1] == '(') {br++;i++;}
        }
        otg = otg*br;
        br = 1;
    }

    printf("%ld\n", otg);
    
    return 0;
}
