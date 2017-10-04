#include<iostream>
#include<cmath>
using namespace std;
int a[10000][2];
int n;
int l=1;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                double f1=sqrt((a[i][1]-a[j][1])*(a[i][1]-a[j][1])+(a[i][2]-a[j][2])*(a[i][2]-a[j][2]));
                double f2=(a[i][1]-a[j][1])*(a[i][1]-a[j][1])+(a[i][2]-a[j][2])*(a[i][2]-a[j][2]);
                if(f1==f2){cout<<"wrong"<<endl;return 0;}
            }
        }
    }
}