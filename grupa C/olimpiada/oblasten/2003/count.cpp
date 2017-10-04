#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
long long a,b,br;
bool prov(long long i)
{
    string s1,s2;
    while(i!=0)
    {
        s1+=i%10+'0';
        i/=10;
    }
    s2=s1;
    reverse(s2.begin(),s2.end());
    if(s2==s1)return true;
    return false;
}
int main()
{
    cin>>a>>b;
    for(long long i=a;i<=b;i++)
    {
        printf("%I64d\n",i);
        if(prov(i)==true)br++;
    }
    cout<<br<<endl;
    return 0;
}
