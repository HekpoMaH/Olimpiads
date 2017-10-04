#include<iostream>
using namespace std;
int m,n,k,i0,j0,r,l;
int num[115][115],br_steps1;
long long int sum=0;
void walk(int i,int j,int br_steps)
{
  if(br_steps==k){sum+=num[i][j];br_steps=0;i=i0;j=j0;}
  if(i+1<=m){walk(i+1,j,br_steps+1);}
  if(j-1>=1){walk(i,j-1,br_steps+1);}
  if(i-1>=1){walk(i-1,j,br_steps+1);}
  if(j+1<=n){walk(i,j+1,br_steps+1);}
}
int main()
{
  l=1;
  cin>>m>>n>>r>>k;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      num[i][j]=l;
      if(l==r){i0=i;j0=j;}
      l++;
    }
  }
  walk(i0,j0,0);
  cout<<sum<<endl;
  return 0;
}
