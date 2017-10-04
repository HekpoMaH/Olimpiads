#include<iostream>
using namespace std;
int main()
{
    double a[125],n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    double p;
    int nmax=1,nmin=1;
    double max=a[1],min=a[1];
    for(int i=2;i<=n;i++)
    {
            if(a[i]>max){max=a[i];nmax=i;}
            if(a[i]<min){min=a[i];nmin=i;}
    }
    p=a[nmax];
    a[nmax]=a[nmin];
    a[nmin]=p;
    for(int i=1;i<=n;i++)
    {
            if(i==n)cout<<a[i]<<endl;
            else cout<<a[i]<<" ";
    }
    system("pause");
    return 0;
}
