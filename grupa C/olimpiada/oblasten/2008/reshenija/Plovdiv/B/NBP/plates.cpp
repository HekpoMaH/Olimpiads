#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[50][1000000];
    int n, m, br=0;
    cin>>n>>m;    
    for(int j=0;j<n;j++)
    for(int i=0;i<m*m;i++)
    cin>>a[j][i];
    int b[50];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m*m;j++)
        b[i]=b[i]+a[i][j]-'0';
    }
    
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
    if(b[i]==b[j]) br++;
    cout<<n-br<<"\n";
    return 0;
}
