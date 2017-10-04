#include<iostream>
using namespace std;
long long t,t1,t2,t3,n;
int main()
{
    cin>>t1>>t2>>t3>>n;
    if(n==1){cout<<t1<<endl;return 0;}
    if(n==2){cout<<t2<<endl;return 0;}
    if(n==3){cout<<t3<<endl;return 0;}
    for(int i=4;i<=n;i++)
    {
        t=t1+t2+t3;
        t1=t2;t2=t3;t3=t;
        //cout<<t1<<" "<<t2<<" "<<t3<<" "<<endl;
    }
    cout<<t<<endl;
    return 0;
}