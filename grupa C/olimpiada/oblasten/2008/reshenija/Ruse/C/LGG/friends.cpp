#include<iostream>
using namespace std;
int main()
{int t,n,m,i,j,k,w; 
cin>>n>>m;
int a[m*2],aa[m*2];
for(i=0;i<m*2;i++)
{cin>>a[i];
aa[i]=0;} 
k=0;
    for(i=0;i<m*2;i=i+2)
    {if(a[i]==1)
    {aa[k]=a[i+1]; 
    k++;}}
cout<<endl;
int br[k];
for(j=0;j<k;j++)
{ br[j]=0;}
                
                for(j=0;j<k;j++)
                for(i=0;i<m*2;i=i+2) 
                {if(aa[j]==a[i]) 
                {br[j]=br[j]+1;
                aa[j]=a[i];}}
                
               
                
for(i=1;i<k;i++)
{if (br[0]<br[i])
{t=br[0];
br[0]=br[i];
br[i]=t;}}
cout<<br[0]<<endl;

return 0;
}
