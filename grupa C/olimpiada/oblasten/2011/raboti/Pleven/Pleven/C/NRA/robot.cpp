#include<iostream>
using namespace std;
long long b,i,a[100][100],j,k,r,s,x,y,m,n;
int main()
{long long br=1;
cin>>m>>n>>r>>k;
for(i=1;i<=m;i++)
 {for(j=1;j<=n;j++)
  {a[i][j]=br;
   if(a[i][j]==r){x=i;y=j;}
br++; }
}
for(i=1;i<=k;i++)
{s+=a[x+i][y]+a[x-i][y]+a[x][y+i]+a[x][y-i];
                 }   
     
   cout<<s<<endl;              
   
    return 0;
}
