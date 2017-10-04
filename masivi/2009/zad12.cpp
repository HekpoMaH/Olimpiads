#include<iomanip>
#include<iostream>
using namespace std;
int main()
{
    double a[101];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    double s=0;
    for(int i=1;i<=n;i++)
    {
            if(a[i]<0)s+=a[i];
    }
    if(s==0)cout<<0<<endl;
    else cout<<setiosflags(ios::fixed)<<setprecision(1)<<s<<endl;
    system("pause");
    return 0;
}
