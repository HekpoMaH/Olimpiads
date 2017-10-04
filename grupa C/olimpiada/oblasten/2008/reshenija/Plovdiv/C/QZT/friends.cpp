#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,sol,tmp,used[2048];
vector<int> a[2048];

void bfs(int v)
{    
 queue<int> q;
 q.push(v);
 used[v]=1;      
 while(q.size()>0)
  {
   tmp=0;
   int s=q.size();
   for(int i=0;i<s;i++)
    {
     int p=q.front();
     for(int j=0;j<a[p].size();j++)
      if(used[a[p][j]]==0) {q.push(a[p][j]); used[a[p][j]]=1; tmp++;}
     q.pop();       
    }               
    if(tmp>sol) sol=tmp;
                     
  }
} 
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=0;i<m;i++)
  {
   int v,v1;
   scanf("%d%d",&v,&v1);
   a[v].push_back(v1);
   a[v1].push_back(v);       
  }
 bfs(1);
 printf("%d\n",sol);
 return 0;    
}
