/*
TASK: odd
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
long long k,a;
int n,i,m;
char ch[22];

int main()
{
    scanf("%d",&n);
    for(;n;n--)
    {
        scanf("%s",&ch);
        a=0;
        m=strlen(ch);
        for(i=0;i<m;i++)
         a=a*10+(ch[i]-'0');
        k^=a;
    }
    cout<<k<<"\n";
}
