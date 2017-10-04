#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
long long n,k;
long long t,f;
long long joy=0;
int main()
{
    cin>>n>>k;
    if(n==k)cout<<0<<endl;
    cout<<(k^(k-1))<<endl;
}

