#include <iostream>
#include <cstdio>
using namespace std;
int a[1000009];
long long n;
void solve()
{
    long long i,j,ans1,s,ans2;
    int l=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&s);
        a[i]=s;
        for(j=0;j<i;j++)
        if(a[i]==a[j]) {a[i]=-1; a[j]=-1;}
    }
    for(i=0;i<n;i++)
    if(a[i]!=-1)
    if(l==0) {ans1=a[i]; l=1;}
    else {ans2=a[i]; break;}
    if(ans1>ans2) cout<<ans2<<" "<<ans1<<endl;
    else cout<<ans1<<" "<<ans2<<endl;
}
int main()
{
    solve();

return 0;
}