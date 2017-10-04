#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
double tf[100004],a[100004],b[100004],x,y;
long long n,s,dt,sp;
long long ovtk(int i,int j)
{
  int k,m,p,w;
  long long c;
  if(i==j)return 0;
  if(j-i==1)
    if(tf[j]<tf[i])return 1;
    else return 0;
  k=(i+j)/2;
  m=k-i+1;p=j-k;
  for(int v=i;v<=k;v++)a[v-i]=tf[v];
  sort(a,a+m);
  for(int v=k+1;v<=j;v++)b[v-k-1]=tf[v];
  sort(b,b+p);
  int v=0;w=0;c=0;
  while(v<m&&w<p)
  {
    if(b[w]<a[v])
    {
      c+=m-v;
      w++;
    }
    else v++;
  }
  c+=ovtk(i,k)+ovtk(k+1,j);
  return c;
}
int main()
{
  scanf("%d%d%d",&n,&s,&dt);
  for(long long i=1;i<=n;i++)
  {
    scanf("%d",&sp);
    x=1000*s;y=sp;
    tf[i]=(i-1)*dt;
    tf[i]+=x/y;
  }
  cout<<ovtk(1,n)<<endl;
  return 0;
}
