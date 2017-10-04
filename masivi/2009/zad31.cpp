#include<iostream>
using namespace std;
int main()
{
    int n;
    int a[120];
    cin>>n;
    int i=1;
    for(i=1;i<=n;i++)cin>>a[i];
    int l=0,j;
    j=n;
    i=1;
    while(l==0&&i<=n/2)
    {
            if(a[i]!=a[(j-i)+1])l=1;
            i++;
    }
    if(l==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    system("pause");
    return 0;
}
