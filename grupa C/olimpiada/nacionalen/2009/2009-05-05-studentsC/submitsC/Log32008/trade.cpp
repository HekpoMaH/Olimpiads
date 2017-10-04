/*
TASK:trade
LANG:C++
*/
#include <iostream>
#include <vector>
#include<cstdio>
#include <cmath>

#define eps 1e-9
using namespace std;

struct graph
{
       int nasl;
       double pr;
};

int n;
vector<graph> v[131072];
double sol[131072];
double koef[131072];

void dfs(int prev,int s)
{
     for(int i=0;i<2;i++)
      if(v[s][i].nasl==prev)
      {
                         koef[s]=2*v[s][i].pr-koef[prev];
                         if(i==0 && v[s][1].nasl!=1) dfs(s,v[s][1].nasl);
                         if(i==1 && v[s][0].nasl!=1) dfs(s,v[s][0].nasl);
      }
}

void solve(int prev,int s)
{
     for(int i=0;i<2;i++)
      if(v[s][i].nasl==prev)
      {
                            sol[s]=2*v[s][i].pr-sol[prev];
                            if(i==0 && v[s][1].nasl!=1) solve(s,v[s][1].nasl);
                            if(i==1 && v[s][0].nasl!=1) solve(s,v[s][0].nasl);
      }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
            int a,b;
            double p;
            cin>>a>>b>>p;
            
            graph tmp;
            tmp.nasl=b; tmp.pr=p;
            v[a].push_back(tmp);
            
            tmp.nasl=a; tmp.pr=p;
            v[b].push_back(tmp);
    }
    
    koef[1]=0;
    dfs(1,v[1][0].nasl);
    
    for(int i=1;i<=n;i++) cout << koef[i] << " ";
    cout << endl;
    
    double kr_koef=koef[v[1][1].nasl];
    double kr_cena=v[1][1].pr;
    if(n%2==0)
    {
              if(fabs(kr_koef-kr_cena*2)>eps) { cout << "impossible\n"; return 0; }
              else { cout << "too many\n"; return 0; }
    }
    cout<<kr_koef<<" "<<kr_cena<<endl;
    cout<<fabs(2*kr_cena-kr_koef)<<endl;
    sol[1]=(2*kr_cena-kr_koef)/2;
    solve(1,v[1][0].nasl);
    for(int i=1;i<n;i++) cout<<sol[i]<<" ";
    cout<<sol[n]<<endl;
    
    return 0;
}
