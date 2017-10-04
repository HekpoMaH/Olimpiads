#include<bits/stdc++.h>
using namespace std;
string bitstring(int x,int n)
{
    string res="";
    for(int i=0;i<n;i++)
    {
        if(x&1)res="1"+res;
        else res="0"+res;
        x>>=1;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    int x=0;
    cout<<bitstring(x,n)<<"0"<<endl;
    for(int i=1;i<(1<<n);i++)
    {
        int p=i&(-i);//nai malak zna4e6t bit
        x^=p;
        cout<<bitstring(x,n)<<" "<<i<<" "<<bitstring((i^(i<<1))>>1,n)<<endl;
    }
}
