#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
typedef unsigned long long lli;
lli p;lli br;
bool chek(int x)
{
    lli a=1;
    //a*=x;
    for(int i=1;i<=p-2;i++)
    {
        a*=x;if((a-1)%p==0)return false;
    }
    a*=x;
    if((a-1)%p==0)return true;
    return false;
}
int main()
{
    cin>>p;
    for(int i=2;i<p;i++)
    {
        if(chek(i))br++;
    }cout<<br<<endl;
}
