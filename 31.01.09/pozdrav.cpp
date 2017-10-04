#include<iostream>
using namespace std;
int main() 
{
    int n;
    cin>>n;
    cout<<"*";
    for(int i=1;i<=n-2;i++)cout<<" ";
    cout<<"* *";
    for(int i=1;i<=n-2;i++)cout<<" ";
    cout<<"* ";
    for(int i=1;i<=n;i++)cout<<"*";
    cout<<endl;
    int r=n/2-1;
    for(int j=1;j<=r;j++)
    {
    cout<<"*";
    for(int i=1;i<=n-2;i++)cout<<" ";
    cout<<"* *";
    for(int i=1;i<=n-2;i++)cout<<" ";
    cout<<"* *"<<endl;
    }
    for(int k=1;k<=2;k++)
    {
            for(int i=1;i<=n;i++)cout<<"*";
            cout<<" ";
    }
    cout<<"*"<<endl;
    for(int j=1;j<=r+1;j++)
    {
    cout<<" ";
    for(int i=1;i<=n-2;i++)cout<<" ";
    cout<<"* *";
    for(int i=1;i<=n-2;i++)cout<<" ";
    cout<<"* *"<<endl;
    }
    system("pause");
    return 0;
}
