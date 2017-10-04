#include<cstdio>
#include<climits>
#include<iostream>
using namespace std;

const int N_max=1001;
int N;
int c[N_max];
int s[N_max][N_max];
int t[N_max][N_max];

void dp()
{
 for(int k=0;k<=N-2;k++)
 {
  int i=k;
  int j=k+2;
  t[i][j]=s[i][j];
 }
 for(int i=0;i<=N;i++)
 {
   for(int j=0;j<=N;j++)
   {
     cout<<t[i][j]<<" ";
   }
   cout<<endl;
 }
 for(int r=3;r<=N;r++)
 for(int k=0;k<=N-r;k++)
 {
  int i=k;
  int j=k+r;
  int m=INT_MAX;
  for(int p=i+1;p<=j-1;p++)
  {
   cout<<"t["<<i<<"]["<<p<<"]="<<t[i][p]<<endl;
   cout<<"t["<<p<<"]["<<j<<"]="<<t[p][j]<<endl;

   int v1=t[i][p];
   int v2=t[ p][j];
   int v=v1+v2;
   if(m>v)m=v;
   cout<<"v="<<v<<"m="<<m<<endl;
   cout<<"-||-||-||-||-||-||-||-||-"<<endl;
  }
  t[i][j]=m+s[i][j];
  cout<<"t["<<i<<"]["<<j<<"]="<<t[i][j]<<endl;
  cout<<"s["<<i<<"]["<<j<<"]="<<s[i][j]<<endl;
  cout<<"|||||||||||||||||||||||||||"<<endl;
 }
 cout<<"-------------------"<<endl;
 for(int i=0;i<=N;i++)
 {
   for(int j=0;j<=N;j++)
   {
     cout<<t[i][j]<<" ";
   }
   cout<<endl;
 }
}

int main()
{
 scanf("%i", &N);
 for(int j=1;j<=N;j++) scanf("%i",&c[j]);

 for(int j=1;j<=N;j++)
 for(int i=0;i<j;i++)
 { int v=0;
   for(int k=i+1;k<=j;k++) v += c[k];
   s[i][j]=v;
 }
 dp();
 printf("%i\n",t[0][N]);
}
