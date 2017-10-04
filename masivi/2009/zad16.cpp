#include<iostream>
using namespace std;
int main()
{
    int a[101];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int p=1;
    for(int i=0;i<n;i++)
    {
            if(a[i]%7==0)p*=a[i];
    }
    if(p==1)cout<<"No"<<endl;
    else cout<<p<<endl;
    system("pause");
    return 0;
}
