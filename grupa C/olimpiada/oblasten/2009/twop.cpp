#include<iostream>
#include<stdio.h>
using namespace std;
int max=5000000;
bool e[5000002];
int n,a,b;
void make()
{
  e[0]=e[1]=1;
  int k=2,i;
  while(k<5000000-1)
  {
   while(e[k]==1) k++;
   i=k+k;
   while(i<=5000000) { e[i]=1; i +=k;}
   k++;
  }
}
int main()
{
  ios::sync_with_stdio(false);
  make();
  cin>>n;
  int mc=0;
  int v,i,c;
  for(int f=1;f<=99;f++)cout<<"e["<<f<<"]="<<e[f]<<endl;
  for(int j=1;j<=n;j++)
  {
    cin>>v;
    i=2;
    c=0;
    while(i<=v/2)
    {
     if(e[i]==0&&e[v-i]==0) c++;
	 i++;
   }
   if(mc<c)mc=c;
  }
  cout<<mc<<endl;
  return 0;
}


