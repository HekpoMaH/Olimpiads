#include<bits/stdc++.h>
using namespace std;
long long m,k;
int ons(int x)
{
    int re=0;
    while(x!=0)
    {
        if(x%2==1)re++;
        x/=2;
    }
    return re;
}
void chek(int n)
{
    int br=0;
    for(int i=n+1;i<=2*n;i++)
    {
        if(ons(i)==k)br++;
    }
    if(br==m)
    {
        cout<<n<<endl;
        exit(0);
    }
}
int main()
{
    cin>>m>>k;
    for(int i=1;;i++)
    {
        chek(i);
    }
}
