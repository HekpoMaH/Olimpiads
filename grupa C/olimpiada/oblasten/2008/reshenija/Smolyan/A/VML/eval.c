#include <stdio.h>
#define MAXC 32
#define issign(a) (a=='+' || a=='-' || a=='*' || a=='/' )

char eq[MAXC];
int mark(char c);
unsigned solve(int st, int en);
unsigned perm2(int pr);
unsigned perm(int pr);
main()
{
    scanf("%s", eq);
    printf("%d\n", solve(0, strlen(eq)));
    return 0;
}

unsigned solve(int st, int en)
{
    unsigned i, ret, level, newst, ns, allpr;
    int sign[MAXC], last, pr;
    ret=1; level=0; allpr=1;
    for(i=0; i<en; i++)
    {
        if(eq[i] == '(')
        {
            if(!level)
            {
                newst = i+1;
                if(i>1 && eq[i-2]==')')
                    allpr++;
            }
            level++;
        }
        if(eq[i] == ')')
        {
            level--;
            if(!level)
                ret*=solve(newst, i);
        }
    }
    
    level=0; ns=0;
    for(i=0; i<en; i++)
    {
        if(eq[i] == '(')
            level++;
        if(eq[i] == ')')
            level--;
        if(!level && issign(eq[i]))
            sign[ns++]=mark(eq[i]);
    }
    
    /*last=0; pr=1;
    for(i=0; i<ns; i++)
        if(sign[i]>0 && (abs(last)==sign[i] || last==0))
        {
            pr++;
            last = sign[i];
        }
        else if(abs(last)!=sign[i])
        {
       */
    pr=1;
    for(i=0; i<ns; i++)
    {
        if(sign[i] == 2)
            pr++;
        else
        {
            ret*=perm2(pr);
            pr=1;
        }
    }
    ret*=perm2(pr);
    
    pr=1;
    for(i=0; i<ns; i++)
    {
        if(sign[i] == 1)
            pr++;
        if(sign[i] == -1)
        {
            ret*=perm2(pr);
            pr=1;
        }
    }
    ret*=perm2(pr);
    
    return ret;
}

int mark(char c)
{
    switch(c)
    {
        case '+':
            return 1;
        case '-':
            return -1;
        case '*':
            return 2;
        case '/':
            return -2;
        /*case '^':
            return -3;*/
    }
}

unsigned perm2(int pr)
{
    int i, ret;
    ret = 1;
    for(i=3; i<=pr; i++)
        ret*=i;
    return ret;
}
unsigned perm(int pr)
{
    int i, ret;
    ret = 1;
    for(i=2; i<=pr; i++)
        ret*=i;
    return ret;
}
