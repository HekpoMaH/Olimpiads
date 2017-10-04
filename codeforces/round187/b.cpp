#include<iostream>
using namespace std;
int a[100009];
int s;
int t,n,o,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        cin>>t>>o;
        //cout<<t<< " "<<o<<endl;
        if(t==1)
        {
            int patka;cin>>patka;a[o]=patka-s;
        }
        if(t==2)
        {
            s+=o;

        }
        if(t==3)
        {
            //cout<<"TT"<<endl;
            cout<<a[o]+s<<endl;
        }
    }
}
