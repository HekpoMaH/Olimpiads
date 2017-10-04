#include<iostream>
using namespace std;
int a[1000],n,mem[1040][1040];
int rec(int i,int j)
{
  if(mem[i][j]!=-1)return mem[j][j];
  if(i==j)return 0;
  int res=9999999;
  for(int k=i;k<j;k++)res=min(res,rec(i,k)+rec(k+1,j));
  for(int k=i;k<=j;k++)res=res+a[k];
  mem[i][j]=res;
  return res;
}
int main()
{
  cin>>n;
  //cout<<mem[0][0];
  for(int l=0;l<=1000;l++)for(int k=0;k<=1000;k++)mem[l][k]=-1;
  for(int i=0;i<n;i++)cin>>a[i];
  cout<<rec(0,n-1)<<endl;
  return 0;
}
