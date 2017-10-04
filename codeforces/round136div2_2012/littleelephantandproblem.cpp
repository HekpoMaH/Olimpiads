#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,a[100002],b[100002],br;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)if(a[i]!=b[i])br++;
    if(br==2||br==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
