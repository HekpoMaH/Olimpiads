#include<bits/stdc++.h>
using namespace std;
int used[20];
int a,b;
bool check(int x)
{
    memset(used,0,sizeof(used));
    while(x!=0)
    {
        if(used[x%10]==1)return false;
        used[x%10]++;
        x/=10;
    }
    return true;
}
int main()
{
    cin>>a>>b;
    int br=0;
    for(int i=a;i<=b;i++)if(check(i))br++;
    cout<<br<<endl;
}
