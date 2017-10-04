#include<iostream>
using namespace std;
int a,b,k;
unsigned long long p;
int main()
{
    cin>>a>>b>>p>>k;
    int l=0,br=0;
    if(a%b==0){while(k){cout<<0;k--;}cout<<endl;}
    else
    {
    while(a<b){a*=10;l++;if(l>1)br++;if(br>=p&&k){cout<<0;k--;}}
    if(l)br++;
    if(br>=p){cout<<a/b;k--;}
    a%=b;
    while(k)
    {
        l=0;
        while(a<b)
        {
            a*=10;
            l++;
            if(l>1){br++;
            if(br>=p&&k)
            {
                cout<<0;k--;
                }
                }
                }
        if(a%b==0){if(k){cout<<a/b;k--;}while(k){cout<<0;k--;}}
        else
        if(br>=p-1&&k){cout<<a/b;br++;k--;}
        a%=b;
        br++;
    }
    cout<<endl;
}
    return 0;
}
