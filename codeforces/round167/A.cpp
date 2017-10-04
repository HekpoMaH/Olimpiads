#include<iostream>
using namespace std;
int main()
{
    int n,a[1015],s=0;;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
    int br=0;
    if((s+1)%(n+1)!=1)br++;
    if((s+2)%(n+1)!=1)br++;
    if((s+3)%(n+1)!=1)br++;
    if((s+4)%(n+1)!=1)br++;
    if((s+5)%(n+1)!=1)br++;cout<<br<<endl;

}
