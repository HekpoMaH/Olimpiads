#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
long long n,k;
long long t,f;
long long joy=-9999999999;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>f>>t;
        if(t>k)
        {
            joy=max(joy,f-t+k);
        }
        else joy=max(joy,f);
    }
    cout<<joy<<endl;
}
