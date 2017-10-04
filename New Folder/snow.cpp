#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int r=n-2,r2=0;
    for(int i=1;i<=n-1;i++)
    {
            for(int j=1;j<=r2;j++)cout<<" ";
            cout<<"*";
            for(int j=1;j<=r;j++)cout<<" ";
            cout<<"*";
            for(int j=1;j<=r;j++)cout<<" ";
            cout<<"*";
            cout<<endl;
            r--;
            r2++;
    }
    for(int i=1;i<=n-1;i++)cout<<" ";
    cout<<"*"<<endl;
    r=0;
    r2=n-2;
    for(int i=n-1;i>=1;i--)
    {
            for(int j=1;j<=r2;j++)cout<<" ";
            cout<<"*";
            for(int j=1;j<=r;j++)cout<<" ";
            cout<<"*";
            for(int j=1;j<=r;j++)cout<<" ";
            cout<<"*";
            cout<<endl;
            r++;
            r2--;
    }
    system("pause");
    return 0;
}
