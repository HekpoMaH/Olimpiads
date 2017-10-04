#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a,b,rez;
int sum;
int main()
{
    cin>>a>>b;
    int u1,u2;
    u1=a.size()-1;u2=b.size()-1;
    //cout<<a<<" "<<b<<endl;
    if(a==b){cout<<0<<endl;return 0;}
    while(u1>=0&&u2>=0)
    {
        sum=(a[u1]-'0')-(b[u2]-'0');
        if(sum<0)sum+=10,a[u1-1]--;
        //cout<<a[u1]<<" "<<b[u2]<<" "<<sum<<endl;
        rez+=sum+'0';
        u1--;u2--;
    }
    for(int i=u1;i>=0;i--)
    {
        if(a[i]<'0')a[i]+=10,a[i-1]--;
        rez+=a[i];
    }
    reverse(rez.begin(),rez.end());
    while(rez[0]=='0')rez.erase(0,1);
    cout<<rez<<endl;
    return 0;
}