#include<iostream>
using namespace std;
int a,b;
int main()
{
    cin>>a>>b;
    if(a==1){cout<<1<<endl;}
    if(a==2){cout<<4<<endl;}
     else
     {long r=0;long s=0;
            for(int i=3;i<=a;i++)
            {r++;s=s+r;}
            s=(a*b)-(2*s);
            cout<<s<<endl;}
      return 0;
}              
