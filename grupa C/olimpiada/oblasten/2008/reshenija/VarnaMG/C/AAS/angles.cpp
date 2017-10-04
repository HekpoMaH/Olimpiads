#include <iostream>
using namespace std;
int n,k,a[1000][1000],b[1000][1000],c[1000][1000];
int main() {
  cin>>n>>k;
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      cin>>a[i][j];
  for(i=0;i<n;i++)
      for(j=1;j<=k;j++){
        b[i][0]+=a[i][j]; 
        c[0][i]+=a[j][i]; 
        }  
    
    for(i=0;i<n;i++)
      for(j=1;j<(n-k);j++)
      {
        b[i][j]=b[i][j-1]-a[i][j]+a[i][k+j];
        c[j][i]=c[j-1][i]-a[j][i]+a[k+j][i];
      }
    for(i=0;i<n;i++)
      for(j=n-k;j<n;j++)
      {
        b[i][j]=b[i][j-1]-a[i][j];
        c[j][i]=c[j-1][i]-a[j][i];
      }
    int m=a[0][0]+b[0][0]+c[0][0],x=1,y=1,s;
    for(i=0;i<n;i++)    
      for(j=0;j<n;j++)
      {s=a[i][j]+b[i][j]+c[i][j];
        if(s>m){m=s;x=i+1;y=j+1;}
          }
    cout<<x<<" "<<y<<"\n";
  return 0;
}
