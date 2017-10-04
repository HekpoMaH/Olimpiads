#include<bits/stdc++.h>
using namespace std;
double a[100][100],cr1[100],cr2[100],b[100];
int n,x;double det=1,u1,u2,del=1;
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

double dett(double tab[][100])
{
    det=1;
    double a2[100][100];
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a2[i][j]=tab[i][j];
    for(int j=1;j<=n;j++)
    {
        for(int i=j+1;i<=n;i++)
        {
            u1=tab[i][j];
            u2=tab[j][j];
            for(int k=j;k<=n;k++)
            {
                tab[i][k]+=tab[j][k]*(-u1/u2);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cout<<tab[i][j]<<" ";
        cout<<endl;
        det*=tab[i][i];
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)tab[i][j]=a2[i][j];
    return det;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
    for(int i=1;i<=n;i++)cin>>b[i];
    int d=dett(a),d2;

    if(d==0){cout<<"Infinity"<<endl;return 0;}
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            swap(a[j][i],b[j]);
        }
        d2=dett(a);
        cout<<"x"<<i<<"= "<<d2/d<<endl;
        for(int j=1;j<=n;j++)
        {
            swap(a[j][i],b[j]);
        }
    }
}
/*
3
1 2 3
1 3 4
1 3 3
40 50 45
*/
