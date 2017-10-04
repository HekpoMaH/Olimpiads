#include<iostream>
using namespace std;
unsigned long long n,a,s,ost1,ost2;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        s+=a;
        if(a%3==1)ost1++;
        if(a%3==2)ost2++;
    }
    if(s%3==0)cout<<0<<endl;
    if(s%3==1&&ost1>0)cout<<1<<endl;
    if(s%3==2&&ost2>0)cout<<1<<endl;
    if(s%3==1&&ost1==0&&ost2>1)cout<<2<<endl;
    if(s%3==2&&ost2==0&&ost1>1)cout<<2<<endl;
    return 0;
}
