/*
TASK: odd
LANG: C++
*/
#include<iostream>
using namespace std;
int main()
{
    long long i,x,a,n;
    cin>>n;
    cin>>a;
    for(i=1;i<n;i++)
    {
        cin>>x;
        a=a^x;
    }
    cout<<a<<'\n';
    return 0;
}
