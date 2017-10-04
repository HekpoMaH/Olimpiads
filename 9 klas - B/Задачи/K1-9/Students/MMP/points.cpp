#include <iostream>
using namespace std;
unsigned long long i,n,k,used[50],br;
void apf(long num)
{
 long j;

         for(j=1;j<=k;j++)
        { 
         num=num+used[j];
         if(num==n-1){br++;num=num-used[j];}
         else
         if(num>n-1)num=num-used[j];
         else
         {
          apf(num);
          num-=used[j];      
         }
        }
       
}
void skokove()
{
 for(i=0;i<=k-1;i++)
  used[i+1]=k-i;;
}
int main()
{
  cin>>n>>k;
  skokove();
  apf(0);
  cout<<br<<endl;


 return 0;        
}

