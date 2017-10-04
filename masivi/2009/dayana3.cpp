#include<iomanip>
#include<iostream>
using namespace std;
int main()
{
    double a[1000],n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++)cin>>a[i];
    double pom;
    for(i=1;i<=n-1;i++)
    {
                       for(int k=1;k<=n-i;k++)
                       {
                               if(a[k]>a[k+1]){
                                               pom=a[k];
                                               a[k]=a[k+1];
                                               a[k+1]=pom;
                                               }
                       }
    }
    cout<<double(a[i]-a[1])<<endl;
    system("pause");
    return 0;
}
