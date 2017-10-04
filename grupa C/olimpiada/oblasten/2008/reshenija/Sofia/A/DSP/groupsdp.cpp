#include<iostream>
#include<vector>

int n, P;
double p[512];
std::vector<double> dp[512][512];

void read()
{
    std::cin>>n>>P;
    for(int i=0;i<=n-1;i++)
        std::cin>>p[i];
}

double get_d(int index)
{
//    std::cout<<"index="<<index<<std::endl;
    double sr = 0;
    for(int i=0;i<=index;i++)
        sr+=p[i];
    sr/=(index+1);
//    std::cout<<"sr="<<sr<<std::endl;
    double d = 0;
    for(int i=0;i<=index;i++)
        d+=(sr-p[i])*(sr-p[i]);
//    std::cout<<"d="<<d<<std::endl;
//    std::cout<<std::endl;
    return d;
}

double get_dsum(std::vector<double> t)
{
    double d = t[0];
    
    double sr = 0;
    for(int i=1;i<t.size();i++)
        sr+=t[i];
    sr/=(t.size()-1);
    
    for(int i=1;i<t.size();i++)
        d+=(sr-t[i])*(sr-t[i]);
    return d;
}

void init()
{
    for(int i=0;i<=n-1;i++)
    {
        dp[i][i].push_back(0);
        dp[i][i].push_back(p[i]);
    }
    for(int j=0;j<=n-1;j++)
    {
        double t = get_d(j);
//        std::cout<<"t="<<t<<std::endl;
        dp[j][0].push_back(t);
        for(int i=0;i<=n-1;i++)
            dp[j][0].push_back(p[i]);
    }
}

double call_dp(int i, int j)
{
//    std::cout<<"i="<<i<<" j="<<j<<std::endl;
    if(i<0 || j<0 || i>n-1 || j>n-1 || j>=i)
        return 0;
    if(dp[i][j].size()>0)
        return dp[i][j][0];
        
    if(dp[i-1][j].size()==0)
        call_dp(i-1, j);
    if(dp[i][j-1].size()==0)
        call_dp(i-1, j-1);
    
    dp[i-1][j].push_back(p[i]);
    double c1 = get_dsum(dp[i-1][j]);
    dp[i-1][j].pop_back();
    
    double c2 = get_dsum(dp[i-1][j-1]);
    
    if(c1<c2)
    {
        dp[i][j] = dp[i-1][j];
        dp[i][j].push_back(p[i]);
    }
    else
    {
        dp[i][j].push_back(dp[i-1][j-1][0] + c2);
        dp[i][j].push_back(p[i]);
    }
    return dp[i][j][0];
}

int main()
{
    read();
    init();
    
/*    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-1;j++)
            if(dp[i][j].size()==0)
                std::cout<<9<<' ';
            else
                std::cout<<dp[i][j][0]<<' ';
        
        std::cout<<std::endl;    
    }*/
    
    call_dp(n-1, P-1);
    
    double sr = 0, ans = dp[n-1][P-1][0];
    for(int i=1;i<dp[n-1][P-1].size();i++)
        sr+=dp[n-1][P-1][i];
    sr/=(dp[n-1][P-1].size()-1);
    for(int i=1;i<dp[n-1][P-1].size();i++)
        ans+=(sr-dp[n-1][P-1][i])*(sr-dp[n-1][P-1][i]);
    
    printf("%.4f \n", ans);
/*    for(int i=1;i<dp[n-1][P-1].size();i++)
        std::cout<<dp[n-1][P-1][i];
    std::cout<<std::endl<<std::endl;*/
    
/*    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-1;j++)
            if(dp[i][j].size()==0)
                std::cout<<9<<' ';
            else
                std::cout<<dp[i][j][0]<<' ';
        
        std::cout<<std::endl;    
    }*/
    
    return 0;
}


