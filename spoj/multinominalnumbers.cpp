#include<iostream>
using namespace std;
unsigned long long n,a[100];
int t;
unsigned long long fact(unsigned long long n)
{
    unsigned long long pr=1;
    for(int i=2;i<=n;i++)pr*=i;
    return pr;
}
void solve()
{
    unsigned long long num=0,sum=0,pr=1;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i],pr*=fact(a[i]);
    sum=fact(sum);
    num=sum/pr;
    while(num%10==0)
    {
        num/=10;
    }
    cout<<num%10<<endl;
}
int main()
{
    cin>>t;
    while(t--){solve();}
    return 0;
}