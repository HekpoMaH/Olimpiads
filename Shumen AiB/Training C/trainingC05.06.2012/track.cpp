//ako mine mine;
#include<iostream>
using namespace std;
int m,n;
long long s;
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)s+=i;
    if(s%m==0&&s/m>=n)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}