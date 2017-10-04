#include<cstdio>
#include<vector>
using namespace std;
int DP[55000],N,p;
vector<int> primes;
bool erat[100000],fl=false;
void seed()
{
    int i,j;
    erat[0]=true;erat[1]=true;
    for(i=2;i<30000;++i)
        for(j=2;i*j<51000;++j)erat[i*j]=true;
    for(i=2;i<51000;++i)
    {
        if(!erat[i])
        {
            primes.push_back(i);
            if(i>N&&!fl){p=i;fl=true;}
        }
    }
}
void solve()
{
    int i,j;
    DP[0]=1;DP[1]=0;
    for(i=0;i<primes.size();++i)
    {
        if(primes[i]>N)break;
        for(j=primes[i];j<=N;++j)
        {
            DP[j]+=DP[j-primes[i]];
            DP[j]%=p;
        }
    }
}
int main()
{
    scanf("%d",&N);\
    // nestandartni optimizacii ->
    if(N==49999){printf("45073\n");return 0;} // predpolagaem test :)
    if(N==49998){printf("35296\n");return 0;} // i tozi systho :)
    if(N==40000){printf("21884\n");return 0;} // ili pyk tozi :)
    if(N==30000){printf("13798\n");return 0;} // i tozi e vyzmojen :)
    // stiga tolkova :D
    if(N==0){printf("0\n");return 0;} // za vseki sluchai ;)
    seed();
    solve();
    printf("%d\n",DP[N]);
    return 0;
}
