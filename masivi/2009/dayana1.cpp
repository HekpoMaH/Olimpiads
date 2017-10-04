#include<iostream>
using namespace std;
int main()
{
    double a[1000],n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++)cin>>a[i];
    i=1;
    int l=0;
    while(i<=n)
    {
                     if(a[i]==0&&l==0)cout<<"Yes"<<endl;
                     if(a[i]==0){cout<<i<<endl;l=1;}
                     i++;
    }
    if(l==0)cout<<"No"<<endl;
    system("pause");
    return 0;
}
