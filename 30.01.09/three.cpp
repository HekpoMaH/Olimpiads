#include<iostream>
using namespace std;
int main()
{
    int n;
    char ch;
    cin>>n>>ch;
    for(int i=1;i<=(n*2-1)/2;i++)cout<<" ";
    cout<<ch<<endl;
    for(int i=2;i<=n-1;i++)
    {
            for(int j=1;j<=n-i;j++)cout<<" ";
            cout<<ch;
            for(int j=1;j<=i*2-3;j++)cout<<" ";
            cout<<ch;
            cout<<endl;            
    }       
    for(int i=1;i<=n;i++)cout<<ch<<" ";
    cout<<endl;
    system("pause");
    return 0;
}
