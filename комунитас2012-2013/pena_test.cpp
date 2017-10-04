#include<iostream>
	#include<vector>
	#include<cstdio>
	using namespace std;
	long long m,n,a[128][128],optp[128][128],k,presents[128][2];
	//а[128][128]-> представлява града като във всяка клетка е записано по колко пари може да даде приятеля от съответния //квартал
	//optp[128][128]-> в optp[i][j] записваме максималното количество пари до клетка с координати i и j
	//presents[128][2]-> в този масив съхраняваме стойностите на всеки подарък
	bool rpath[128][128];
	//rpath[128][128]-> матрица на самия път; true ако сме минали оттам, false, ако не сме
	long long money;
	long long dp[128][20000];
	//dp[128][20000]-> dp[i][j] показва максималната влюбеност, ако имахме всички подаръци от 1 до i и j лева
	bool taken[128][20000];
	//taken[128][20000]-> показва дали вземаме даден подарък, ако имахме всички подаръци от 1 до i и j лева
	void solvepath()//функция за пресмятане на пътя
	{
    		for(int i=1;i<=m;i++)
    		{
        			for(int j=1;j<=n;j++)
       	 		{
           	      		optp[i][j]=max(optp[i-1][j],optp[i][j-1])+a[i][j];
        			}
   		 }
	}
	//функции за намиране и извеждане на самия път
//функции за намиране и извеждане на самия път
void findpath(int x,int y)
{
    while(x!=1||y!=1)
    {
        rpath[x][y]=true;
        if(x==1)y--;
        else if(y==1)x--;
        else if(optp[x-1][y]>optp[x][y-1])x--;
        else y--;
    }
    rpath[1][1]=true;
}
void printpath()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(rpath[i][j]==true)printf("X");
            else printf("O");
        }
        printf("\n");
    }
}
//функции за пресмятане и извеждане на начина на закупуване
void solvepresents()
{
    for(long long i=1;i<=money;i++)dp[0][i]=0;
    for(int i=1;i<=k;i++)
    {
        for(long long j=1;j<=money;j++)
        {
            if(j>=presents[i][j])
            {
                dp[i][j]=max(dp[i-1][j],presents[i][2]+dp[i-1][j-presents[i][1]]);
                taken[i][j]=1;
            }
            else{dp[i][j]=dp[i-1][j];taken[i][j]=0;}
        }
    }
}
void printpresents()
{
    vector<int> ans;
    long long x=money;
    for(int i=k;i>=1;i--)
    {
        if(taken[i][x])
        {
            x-=presents[i][1];
            ans.push_back(i);
        }
    }
    printf("%d\n",ans.size());
    for(int i=ans.size()-1;i>0;i--)printf("%d ",ans[i]);
    printf("%d\n",ans[0]);
}
//главна функция; служи за въвеждане и извикване на останалите
int main()
{
    scanf("%I64d%I64d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%I64d",&a[i][j]);
        }
    }
    solvepath();
    money=optp[m][n];
    findpath(m,n);
    scanf("%I64d",&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%I64d%I64d",&presents[i][1],&presents[i][2]);
    }
    printf("%I64d\n",optp[m][n]);
    printpath();
    solvepresents();
    printpresents();
    return 0;
}
