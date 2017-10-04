#include<iostream>
using namespace std;
int pp,pv,a,b,c,d,m1,m2,m3,l1,l2,l3,br1,br2;
int main()
{
    cin>>a>>b>>c>>d;
    cin>>m1>>m2>>m3;
    pp=1;pv=1;
    for(int i=1;i<=999;i++)
    {
        if(i==m1)
        {
            if(pp==1&&pv==1)l1=2;
            if(pp==1&&pv!=1)l1=1;
            if(pp!=1&&pv==1)l1=1;
            if(pp==0&&pv==0)l1=0;
        }
        if(i==m2)
        {
            if(pp==1&&pv==1)l2=2;
            if(pp==1&&pv!=1)l2=1;
            if(pp!=1&&pv==1)l2=1;
            if(pp==0&&pv==0)l2=0;
        }
        if(i==m3)
        {
            if(pp==1&&pv==1)l3=2;
            if(pp==1&&pv!=1)l3=1;
            if(pp!=1&&pv==1)l3=1;
            if(pp==0&&pv==0)l3=0;
        }
        br1++;
        br2++;
        if(br1==a&&pp==1){pp=0;br1=0;}
        if(br1==b&&pp==0){pp=1;br1=0;}
        if(br2==c&&pv==1){pv=0;br2=0;}
        if(br2==d&&pv==0){pv=1;br2=0;}
    }
    if(l1==2)cout<<"both"<<endl;
    if(l1==1)cout<<"one"<<endl;
    if(l1==0)cout<<"none"<<endl;
    if(l2==2)cout<<"both"<<endl;
    if(l2==1)cout<<"one"<<endl;
    if(l2==0)cout<<"none"<<endl;
    if(l3==2)cout<<"both"<<endl;
    if(l3==1)cout<<"one"<<endl;
    if(l3==0)cout<<"none"<<endl;
    return 0;
}