/*
TASK: diet
LANG: C++
*/

#include<cstdio>
int a,b,c,days,cut,x,y;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    days=(a*10+b*20+c*30)/60;
    cut=(c-a)/2;
    printf("%d %d\n",days,cut);
    return 0;
}

/*
    (x+y)=(c-a)/2
    10*a+20*b+30*c
*/
