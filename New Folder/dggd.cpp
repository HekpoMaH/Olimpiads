#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int in=n,zv=1;
    for(int i=1;i<=n;i++)
    {
            for(int j=1;j<=in;j++)cout<<" ";
            for(int j=1;j<=zv;j++)cout<<"*";
            zv=zv+2;
            in--;
            cout<<endl;
    }
    for(int i=1;i<=n;i++)cout<<"*";
    cout<<" ";
    for(int i=1;i<=n;i++)cout<<"*";
    in=1;
    zv=zv-2;
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
            for(int j=1;j<=in;j++)cout<<" ";
            for(int j=1;j<=zv;j++)cout<<"*";
            zv=zv-2;
            in++;
            cout<<endl;
    }
    system("pause");
    return 0;
}
