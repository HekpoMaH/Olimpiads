#include<iostream>
using namespace std;
int n,q;
double f[3002][505];
double f1,f2,f3,f4,f5,f6;
int main()
{
    cin>>n>>q;
    for(int i=1;i<=6;i++)f[1][i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=q;j++)
        {
            f1=0;f2=0;f3=0;f4=0;f5=0;f6=0;
            if(j-1>=0)f1=f[i-1][j-1];
            if(j-2>=0)f2=f[i-1][j-2];
            if(j-3>=0)f3=f[i-1][j-3];
            if(j-4>=0)f4=f[i-1][j-4];
            if(j-5>=0)f5=f[i-1][j-5];
            if(j-6>=0)f6=f[i-1][j-6];
            f[i][j]=f1+f2+f3+f4+f5+f6;
        }
    }
    double all=1;
    for(int i=1;i<=n;i++)all*=6;
    cout<<f[n][q]/all<<endl;
    return 0;
}