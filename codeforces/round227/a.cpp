#include<bits/stdc++.h>
using namespace std;
int h1,m1,h2,m2;
int main()
{
    scanf("%d:%d",&h1,&m1);
    scanf("%d:%d",&h2,&m2);
    h1-=h2;
    if(h1<0)h1+=24;
    m1-=m2;
    if(m1<0)
    h1--,m1+=60;
    if(h1<0)h1+=24;
    printf("%02d:%02d\n",h1,m1);
}
