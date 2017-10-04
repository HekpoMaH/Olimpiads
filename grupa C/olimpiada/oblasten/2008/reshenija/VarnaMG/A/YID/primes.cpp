#include<stdio.h>
#include<vector>
using namespace std;
int eraa[50001]={0};
vector <int> pr;
int S=0,N,mid=0;
void gen(int n,int k);
void era(int n);
int main()
{
 int i,n,j;
 scanf("%d",&n);
 N=n;
 era(n);
 j=pr.size();
 j--;
 for(i=0;i<=mid;i++)
  gen(n,pr[i]);
 S%=pr[j];
 printf("%d\n",S);
 return 0;
}
void era(int n)
{
 int i,j,br=0;
 eraa[0]=eraa[1]=1;
 for(i=2;i<50000;i++)
  if(!eraa[i])
  {
   pr.push_back(i);
   if(i>=n/2&&mid==0)mid=br;
   br++;
   if(i>n)return;
   for(j=2*i;j<50000;j+=i)
   eraa[j]=1;
  }
 return;
}
void gen(int n,int k)
{
 if(n<=0)return;
 if(!eraa[n]&&N!=n)S++;
 gen(n-k,k);
 return;
}
