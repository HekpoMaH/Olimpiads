#include<bits/stdc++.h>
using namespace std;
int g(int n)
{
    return n^(n>>1);
    //1101
    //0110
    //1011
}
int main()
{
    int n;
    cin>>n;
    cout<<g(n)<<endl;
}
