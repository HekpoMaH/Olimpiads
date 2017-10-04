#include<iostream>
#include<cmath>
using namespace std;
int n,m,t,kx,ky,br,used[1000][1000];
int main()
{
    cin>>n>>m>>t;
    while(cin>>kx)
    {
        cin>>ky;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)if(!used[i][j])if(abs(i-kx)+abs(j-ky)<=t){br++;used[i][j]=1;}
        }
    }
    cout<<n*m-br<<endl;
    return 0;
}