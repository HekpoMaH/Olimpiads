#include<iostream>
using namespace std;
long long m,n,z,mp=1,mq=1,p;
int main()
{
    cin>>z>>m>>n;
    for(int q=2;q<=z;q++)
    {
        p=m*q/n+1;
        if(p*mq<q*mp){mp=p;mq=q;}
    }
    cout<<mp<<" "<<mq<<endl;
    return 0;
}