#include<iostream>
using namespace std;
long long m,n,z,p;
long long ans1=1,ans2=1;
int main()
{
    cin>>z>>m>>n;
    for(long long q=2;q<=z;q++)
    {
        p=m*q/n+1;
        if(p*ans2<q*ans1){ans1=p;ans2=q;}
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
