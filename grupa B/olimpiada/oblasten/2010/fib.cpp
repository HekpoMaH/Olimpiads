#include<iostream>
using namespace std;
int s[100][100];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long  n,a=1,b=1,i;
    cin>>n;
    if(n==1 || n==2)
    {
        cout<<1<<'\n';
        return 0;
    }
    if(n<100000)
    {
        for(i=3;i<=n;i++)
        {
            a=(a+b)%100;
            swap(a,b);
        }
        if(b<10)cout<<0;
        cout<<b<<'\n';
        return 0;
    }
    for(i=2;!s[a][b];i++)
    {
        s[a][b]=i;
        a=(a+b)%100;
        swap(a,b);
    }
    n-=s[a][b];
    i-=s[a][b];
    n%=i;
    for(i=0;i<n;i++)
    {
        a=(a+b)%100;
        swap(a,b);
    }
    if(b<10)cout<<0;
    cout<<b<<'\n';
}
