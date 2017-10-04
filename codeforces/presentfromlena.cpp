#include<iostream>
#include<string>
using namespace std;
int n;
string s;
int main()
{
    cin>>n;
    for(int i=1;i<=2*n;i++)s+=" ";
    for(int i=0;i<=n;i++)
    {
        cout<<s;
        s.erase(0,2);
        if(i==0){cout<<0<<endl;continue;}
        for(int j=0;j<=i;j++)cout<<j<<" ";
        if(i!=0)
        {
            for(int j=i-1;j>=1;j--)cout<<j<<" ";
            cout<<0;
        }
        cout<<endl;
    }
    for(int i=n-1;i>=0;i--)
    {
        s+="  ";
        cout<<s;
        if(i==0){cout<<0<<endl;continue;}
        for(int j=0;j<=i;j++)cout<<j<<" ";
        if(i!=0)
        {
            for(int j=i-1;j>=1;j--)cout<<j<<" ";
            cout<<0;
        }
        cout<<endl;
    }
    return 0;
}