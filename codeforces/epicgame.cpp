#include<iostream>
#include<algorithm>
using namespace std;
int a[3],n,turn;
int main()
{
    cin>>a[0]>>a[1]>>n;
    while(n-=__gcd(a[turn],n))turn^=1;
    cout<<turn<<endl;
    return 0;
}