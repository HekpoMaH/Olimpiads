#include<bits/stdc++.h>
using namespace std;
int p,q,n;
int br;
void rec(int a,int b)
{
    if(a==p&&b==q){br++;return;}
    if(a<p||b<q)return;
    rec(a-1,b);
    if(b-1>a)rec(a,b-1);
}
int main()
{
    cin>>p>>q>>n;
    rec(n-1,n);
    cout<<br<<endl;
}
