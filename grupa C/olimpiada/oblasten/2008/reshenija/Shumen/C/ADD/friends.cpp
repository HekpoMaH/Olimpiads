#include<cstdio>
#include<vector>
#include<queue>
//#include<iostream>
using namespace std;
vector <int> v[2048];
int n,m,u[2048],br,br2;
void create()
{
 int i,n1,p;
 queue <int> q;
 q.push(1);
 u[1]=1;
 br=1;
 m=0;
 while(!q.empty())
 {
  while(br)
  {
   p=q.front();
   //cout<<p<<endl;
   q.pop();
   n1=v[p].size();
   for(i=0;i<n1;i++)
    if(u[v[p][i]]==0)
    {
     q.push(v[p][i]);
     u[v[p][i]]=1;
     br2++;
    }
   br--;
  }
  //cout<<0<<endl;
  if(br2>m)m=br2;
  br=br2;
  br2=0;
 }
}
int main()
{
 int i,x,y;
 scanf("%d%d",&n,&m);
 for(i=0;i<m;i++)
 {
  scanf("%d%d",&x,&y);
  v[x].push_back(y);
  v[y].push_back(x);
 }
 create();
 printf("%d",m);
 return 0;
}
