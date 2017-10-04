#include <iostream>

using namespace std;



int main(){
int m, n, r, k;
cin>>m>>n>>r>>k;
int a[m+1][n+1];
int c=1;
for(int i=0;i<m+1;i++)
  for(int j=0;j<n+1;j++){
    a[i][j]=0;

  }
for(int i=0;i<m;i++)
  for(int j=0;j<n;j++){
    a[i][j]=c;

    c++;
  }
int sum;
int x=r%n-1;
int y=r/n;

if(k==1)
  sum=a[x+1][y]+a[x-1][y]+a[x][y+1]+a[x][y-1];
if(k==2)
  sum=a[x+2][y]+a[x-2][y]+a[x][y+2]+a[x][y-2]+2*a[x-1][y-1]+2*a[x-1][y+1]+2*a[x+1][y+1]+2*a[x+1][y-1];

cout<<sum<<endl;
return 0;
}
