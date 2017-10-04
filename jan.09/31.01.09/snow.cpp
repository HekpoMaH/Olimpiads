#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int r=n-2;
    for(int i=n-1;i>=1;i--)
    {
            for(int j=0;j<=n-i-1;j++)cout<<" ";
            cout<<"*";
            for(int j=1;j<=r;j++)cout<<" ";
            cout<<"*";
            for(int j=1;j<=r;j++)cout<<" ";
            cout<<"*"<<endl;
            r--;
    }
    for(int i=1;i<=1+n-1;i++)cout<<" ";
    cout<<"*"<<endl;
    r=0;
    for(int i=1;i<=n-1;i++)
    {
            for(int j=0;j<=n-i-1;j++)cout<<" ";
            cout<<"*";
            for(int j=1;j<=r;j++)cout<<" ";
            cout<<"*";
            for(int j=1;j<=r;j++)cout<<" ";
            cout<<"*"<<endl;
            r++;
    }
    system("pause");
    return 0;
}
