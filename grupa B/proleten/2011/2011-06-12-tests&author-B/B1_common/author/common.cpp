#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

const int K=1001;
vector<int> a[K];
int k;
int d[K], p[K];

bool eq()
{
 for(int i=1;i<k;i++)
  if(a[0][p[0]]!=a[i][p[i]]) return false;
 return true;          
}

int main()
{
 scanf("%d",&k);
 for(int i=0;i<k;i++) scanf("%d",&d[i]);
 for(int i=0;i<k;i++)
 for(int j=0;j<d[i];j++) 
  {int v; scanf("%d",&v); a[i].push_back(v);}
  
 for(int i=0;i<k;i++) sort(a[i].begin(),a[i].end()); 

 for(int i=0;i<k;i++) p[i]=0;

 bool b=true;
 while(b)
 {
 b=false;
 for(int i1=0;i1<k-1;i1++)
 for(int i2=i1+1;i2<k;i2++)
 {
  if(eq()){printf("%d\n",a[0][p[0]]); return 0;}
  if(a[i1][p[i1]] < a[i2][p[i2]]) 
  {if(p[i1]<d[i1]-1) {b=true; p[i1]++;}}
   else if(a[i1][p[i1]] > a[i2][p[i2]]) 
  {if(p[i2]<d[i2]-1) {b=true; p[i2]++;}}
 }
 }
 printf("x\n");
}
