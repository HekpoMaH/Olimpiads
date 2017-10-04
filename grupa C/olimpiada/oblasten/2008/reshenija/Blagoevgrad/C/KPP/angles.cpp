#include<iostream>
using namespace std;
int a[1000][1000];int br=1;
int main()
{int n,k;int maxs=-1000;int x,y;
cin>>n>>k;
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
cin>>a[i][j];}
int s=0;
for(int i=0;i<n;i++)
{s=0;
for(int j=0;j<n;j++){s=0;
for(int l=0;l<=k;l++)
{s=s+a[i+l][j]+a[i][j+l];}s=s-a[i][j];if(maxs<s){x=i;y=j;maxs=s;}}}cout<<x+1<<" "<<y+1;cout<<"\n";


    
    
    
    
    
    system("pause");
    return 0;
}
