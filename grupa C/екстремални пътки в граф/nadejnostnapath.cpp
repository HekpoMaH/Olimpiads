#include<iostream>
using namespace std;
double a[100][100];
int n,m;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                a[i][j]=max(a[i][j],a[i][k]*a[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
5
1 0.5 0.2 0.9 0
0.5 1 0.2 0.3 1
0.2 0.2 1 0 0.5
0.9 0.3 0 1 0.6
0 1 0.5 0.6 1
*/