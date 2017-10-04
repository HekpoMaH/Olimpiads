#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int in=n,z=1;
    for(int i=1;i<=n;i++)
    {
            for(int j=1;j<=in;j++)cout<<" ";
            for(int j=1;j<=z;j++)cout<<"*";
            z=z+2;
            in--;
            cout<<endl;
    }
    for(int i=1;i<=n;i++)cout<<"*";
    cout<<" ";
    for(int i=1;i<=n;i++)cout<<"*";
    cout<<endl;
    in=1;z=z-2;
    for(int i=1;i<=n;i++)
    {
            for(int j=1;j<=in;j++)cout<<" ";
            for(int j=1;j<=z;j++)cout<<"*";
            z=z-2;
            in++;
            cout<<endl;
    }
    system("pause");
    return 0;
}
