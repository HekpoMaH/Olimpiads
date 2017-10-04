#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
int n,k;
int main()
{
    cin>>n>>k;
    if(k==1&&n==1){cout<<"a"<<endl;return 0;}
    if(n<k||k==1){cout<<-1<<endl;return 0;}
    string s="";
    if(k==2)
    {
        for(int i=1;i<=n;i++)
        {
            if(i%2==1)s+='a';else s+='b';
        }
        cout<<s<<endl;return 0;
    }
    int fff=n-k+1;//if(k%2!=0)fff--;
    for(int i=0;i<=fff;i++)
    {
        if(i%2==0)s+='a';else s+='b';
    }//if(fff%2!=0)s+='a';
    for(int i=2;i<k;i++)s+=(char)('a'+i);cout<<s<<endl;
}

