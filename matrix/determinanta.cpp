#include<bits/stdc++.h>
using namespace std;
double a[100][100];
int cr1[100],cr2[100];
int n,x,det=1;
double u1,u2;
int nod(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
    for(int j=1;j<=n;j++)
    {
        for(int i=j+1;i<=n;i++)
        {
            u1=a[i][j];
            u2=a[j][j];
            for(int k=j;k<=n;k++)
            {
                a[i][k]+=a[j][k]*(-u1/u2);
            }
        }
        for(int i1=1;i1<=n;i1++)
        {
            for(int j1=1;j1<=n;j1++)cout<<a[i1][j1]<<" ";
            cout<<endl;
            //det*=a[i][i];
        }cout<<"---------------------"<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";
        cout<<endl;
        det*=a[i][i];
    }
    cout<<det<<endl;
}
