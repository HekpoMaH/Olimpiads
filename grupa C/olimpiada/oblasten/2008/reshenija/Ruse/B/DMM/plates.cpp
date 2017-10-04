#include<iostream>
using namespace std;
int b[1000][30],d[1000][30],s[30],z[30];
int main ()
{
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    cin>>a[i][j];
    for(int i=0;i<m;i++)
    for(int j=0;j<n-1;j++)
    {if((a[i][j]==10)&&(a[i][j+1]==10)||(a[i][j]==01)&&(a[i][j+1]==01)||(a[i][j]==10)&&(a[i][j+1]==01)||(a[i][j]==01)&&(a[i][j+1]==10))
    b[i][j]=1;
    if((a[i][j]==11)&&(a[i][j+1]==11))
    d[i][j]=1;}
    int br=0;
    for(int i=0;i<m;i++)
    {for(int j=0;j<n;j++)
    {s[br]=s[br]+b[i][j]+d[i][j];}
    br++;}
    int p=0;
    for(int i=0;i<br-1;i++)
    {while(s[i]==s[i+1])
    {z[p]=z[p]+1;i++;}p++;}
    sort(z,z+p);
    if(z[0]!=0)
    cout<<z[0]+1<<endl;
    else
    cout<<z[0]<<endl;
    return 0;
}
    
    
