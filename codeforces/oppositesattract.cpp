#include<iostream>
using namespace std;
long long n,c[22],a,br;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        c[a+10]++;
    }
    int idx=0;
    while(idx<=9)
    {
        
        br+=c[idx]*c[20-idx];idx++;
    }
    br+=c[10]*(c[10]-1)/2;
    cout<<br<<endl;
    return 0;
}