#include<iostream>
using namespace std;
int uk,n,br;
long long m;
int maxmax=1;
char b[2001],a[2001][2001];
int otbor()
{
 int i,j;   
 br=0;
 for(i=1;i<=n;i++)
  if(b[i]=='1')
   for(j=1;j<=n;j++)
    if( (a[i][j]=='1') && (b[j]=='0') )
     {
      b[j]='2';
      uk++;
      br++;            
     }
 for(i=1;i<=n;i++)
  if(b[i]=='2')
   b[i]='1';   
 if(br>maxmax)
  maxmax=br;  
 if(uk<n)
  otbor();
 return maxmax;         
}

int main()
{
long long i,j,x,y;    
cin>>n>>m;
for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
  a[i][j]='0';
for(i=1;i<=m;i++)
 {
  cin>>x>>y;
  a[x][y]='1';
  a[y][x]='1';
 } 
for(i=2;i<=n;i++)
 b[i]='0';
b[1]='1';
uk=1;
cout<<otbor()<<endl; 
return 0;
}
