#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
long long n;
bool check(long long x)
{
    int  used[11];
    memset(used,0,sizeof(used));
    while(x!=0)
    {
        if(used[x%10]==1)return false;
        used[x%10]=1;
        x/=10;
    }
    return true;
}
int main()
{
    cin>>n;
    while(1)
    {
        n++;if(check(n)==true){cout<<n<<endl;break;}
    }
}
