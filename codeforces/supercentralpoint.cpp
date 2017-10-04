#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
int a[202][3],br,l1,l2,l3,l4;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2];
    for(int i=1;i<=n;i++)
    {
        l1=0;l2=0;l3=0;l4=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j][1]>a[i][1]&&a[i][2]==a[j][2])l1=1;
            if(a[j][1]<a[i][1]&&a[i][2]==a[j][2])l2=1;
            if(a[j][1]==a[i][1]&&a[i][2]<a[j][2])l3=1;
            if(a[j][1]==a[i][1]&&a[i][2]>a[j][2])l4=1;
        }
        if(l1&&l2&&l3&&l4)br++;
    }
    cout<<br<<endl;
    return 0;
}
