#include<iostream>
using namespace std;
int main()
{
    int a[101];
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    int x,l=0,p;
    cin>>x;
    i=1;
    while(i<=n&&l==0)
    {
            if(a[i]==x){l++;p=i;}
            i++;
    }
    if(l==0)cout<<"No"<<endl;
    else cout<<p<<endl;
    system("pause");
    return 0;
}
