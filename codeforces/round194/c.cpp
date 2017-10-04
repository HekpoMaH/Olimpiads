#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n,pw;
int main()
{
    cin>>n;
    pw=1;
    while(pw<n&&n%pw==0)pw*=3;
    cout<<n/pw+min(n%pw,(ull)1)<<endl;
}


