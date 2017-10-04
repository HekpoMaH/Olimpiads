#include<cstdio>
#include<algorithm>
long long sum[100010];
long long data[100010];
int n,k;
long long geti(int a,int b)
{
    return sum[b]-sum[(a+b)/2-1+((a+b)&1)]-(sum[(a+b)/2]-sum[a-1]);
}
long long dp[100010];
int pos[100010],posize,cpos;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&data[i]);
        sum[i]=sum[i-1]+data[i];
    }
    dp[1]=0;
    posize=1;
    if(n>6000)
    {
        printf("%lld\n",geti(1,n));
        return 0;
    }
    for(int i=2;i<=n;i++)
    {
        dp[i]=geti(1,i);
        /*
        long long beste=geti(pos[cpos]+1,i)+dp[pos[cpos]];
        while(cpos<posize-1)
        {
            if(beste<geti(pos[cpos+1]+1,i)+dp[pos[cpos+1]]) break;
            beste=geti(pos[cpos+1]+1,i)+dp[pos[cpos+1]];
            cpos++;
        }
        if(dp[i]>beste+k) dp[i]=beste+k;
        if(data[i]==data[i-1]&&dp[i]==dp[i-1]) pos[posize-1]=i;
        else
            pos[posize++]=i; //*/
        for(int j=1;j<i;j++)
        if(dp[i]>geti(j+1,i)+dp[j]+k) dp[i]=dp[j]+k+geti(j+1,i);
    }
    printf("%lld\n",dp[n]);
}
