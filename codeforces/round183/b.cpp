#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<iomanip>
using namespace std;
long long yy1,m1,d1,yy2,m2,d2,dd1,dd2;
int month[22]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    scanf("%I64d:%I64d:%I64d",&yy1,&m1,&d1);
    scanf("%I64d:%I64d:%I64d",&yy2,&m2,&d2);
    int vis=0;
    for(int i=1;i<yy1;i++)if((i%4==0&&i%100!=0)||i%400==0)vis++;
    dd1+=vis*366+(yy1-vis)*365;
    if((yy1%4==0&&yy1%100!=0)||yy1%400==0)month[2]=29;
    for(int i=1;i<m1;i++)dd1+=month[i];
    dd1+=d1;
    month[2]=28;
    vis=0;
    for(int i=1;i<yy2;i++)if((i%4==0&&i%100!=0)||i%400==0)vis++;
    dd2+=vis*366+(yy2-vis)*365;
    if((yy2%4==0&&yy2%100!=0)||yy2%400==0)month[2]=29;
    //cout<<month[2]<<endl;
    for(int i=1;i<m2;i++)dd2+=month[i];
    dd2+=d2;
    //cout<<dd1<<" "<<dd2<<endl;
    cout<<abs(dd1-dd2)<<endl;
}

//497
