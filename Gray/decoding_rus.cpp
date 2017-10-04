#include<bits/stdc++.h>
using namespace std;
int rev_g(int g)
{
    int n=0;
    for(;g;g>>=1)n^=g;
    return n;
}
int main()
{
    int g;
    cin>>g;
    cout<<rev_g(g)<<endl;
}
