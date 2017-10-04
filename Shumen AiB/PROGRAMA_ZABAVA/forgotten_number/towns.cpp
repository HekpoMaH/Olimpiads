#include<iostream>
#include<string>
using namespace std;
int n;
int xx[100][100];int a[100][100],br,br2,zz=1;
string x;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        for(int j=0;j<n;j++)if(x[j]=='C')br++,xx[i][j+1]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=zz;
            if(xx[i][j]==1)br2++;
            if(br2==br/2)zz=2;
            cout<<a[i][j];
        }cout<<endl;
    }
}

