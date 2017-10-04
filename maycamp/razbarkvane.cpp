#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[9],br,n1;
int main()
{
    cin>>n;
    n1=n;
    while(n!=0)
    {
        br++;
        a[br]=n%10;
        n/=10;
    }
    n=br;
    sort(a+1,a+n+1);
    int num,ans=100000000;
    while(next_permutation(a+1,a+n+1))
    {
        num=0;
        for(int i=1;i<=n;i++)num*=10,num+=a[i];
        if(num>n1)ans=min(num,ans);
    }
    if(ans==100000000)cout<<0<<endl;
    else cout<<ans<<endl;
    return 0;
}