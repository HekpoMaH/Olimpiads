#include<iomanip>
#include<iostream>
using namespace std;
int main()
{
    int a[101];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int br=0,s=0;
    for(int i=1;i<=n;i++)
    {
            if(a[i]>0){br++;s+=a[i];}
    }
    double sr;
    sr=(double)s/br;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<sr<<endl;
    system("pause");
    return 0;
}
