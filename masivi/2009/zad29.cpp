#include<iostream>
using namespace std;
int main()
{
    int n;
    int a[100];
    cin>>n;
    int i=0;
    for(i=0;i<n;i++)cin>>a[i];
    int l=0;
    i=0;
    while(l==0&&i<n-1)
    {
            if(a[i]==0&&a[i+1]==a[i])l=1;
            i++;
    }
    if(l==0)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    system("pause");
    return 0;
}
