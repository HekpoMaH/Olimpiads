#include<iostream>
#include<cstring>
using namespace std;
long long fact[9];
long long a,b,c,d;
long long comb[52][52],st,all,ans;
long long gc(int n,int k)
{
    if(k==0)return 1;
    if(n<k)return 0;
    if(comb[n][k]!=-1)return comb[n][k];
    comb[n][k]=gc(n-1,k)+gc(n-1,k-1);
    return comb[n][k];
}
void solve(int num,int pos)
{
    if(num==a)
    {
        if(st+c-pos-d-d+2>0)all+=st+c-pos-d-d+2;
        ans+=gc(all,b)*fact[a]*fact[b];
        //cout<<gc(all,b)<<endl;
        if(st+c-pos-d-d+2>0)all-=st+c-pos-d-d+2;
        return;
    }
    for(int i=pos+1;i<=c;i++)
    {
        if(num==0)
        {
            st=i-1;
            solve(num+1,i);
        }
        else
        {
            if(i-pos-d-d+1>0)all+=i-pos-d-d+1;
            solve(num+1,i);
            if(i-pos-d-d+1>0)all-=i-pos-d-d+1;
        }
    }
}
int main()
{
    cin>>a>>b>>c>>d;
    fact[0]=1;
    for(int i=1;i<=6;i++)fact[i]=fact[i-1]*i;
    memset(comb,-1,sizeof(comb));
    solve(0,0);
    cout<<ans<<endl;
    return 0;
}