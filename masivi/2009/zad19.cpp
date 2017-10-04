#include<iostream>
using namespace std;
int main()
{
    double a[1000];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    double min=a[1],max=a[1],pom;
    int nmin=1,nmax=1;
    for(int i=1;i<=n;i++)
    {
            if(a[i]>max){max=a[i];nmax=i;}
            if(a[i]<min){min=a[i];nmin=i;}
    }
    pom=a[nmin];
    a[nmin]=a[nmax];
    a[nmax]=pom;
    for(int i=1;i<n;i++)cout<<a[i]<<" ";
    cout<<a[n]<<endl;
    system("pause");
    return 0;
}
