#include <iostream>
using namespace std;
long fl,br,x,x1,y,y1,n,k,j,i,a[501][501],mini,maxi;
int main()
{
 cin>>n;
 for(k=1;k<=n;k++)
  {
    scanf("%d%d%d%d",&x,&y,&x1,&y1);                
     for(i=x;i<=x1;i++)
      for(j=y;j<=y1;j++)
       a[i][j]++;  
       maxi=max(x,maxi);
       maxi=max(x1,maxi);
       mini=max(y,mini);
       mini=max(y1,mini);            
  }
 for(i=0;i<=maxi;i++)
  for(j=0;j<=mini;j++)
 {
   fl=0;
   if(a[i][j]!=0)br++;
   if(a[i][j]==a[i][j+1] && a[i][j]>1 ){br++;fl=1;} 
   if(fl=1)a[i][j]=1;
   if(a[i][j]==a[i][j-1] && a[i][j]>1 ){br++;fl=1;}
   if(fl=1)a[i][j]=1;
   if(a[i][j]==a[i-1][j] && a[i][j]>1 ){br++;fl=1;}
   if(fl=1)a[i][j]=1;
   if(a[i][j]==a[i+1][j] && a[i][j]>1 ){br++;fl=1;}
   if(fl=1)a[i][j]=1;
 }
   cout<<br<<endl;
 
 return 0;       
}
