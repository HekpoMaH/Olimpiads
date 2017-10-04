//
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
string s[10001],s1[10001],s2;
int a[10001][2];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        cin>>s1[i];
    }
    sort(s1,s1+n);
    for(int i=1;i<n;i++)
    {
        if(s1[i]==s1[i-1]){cout<<s1[i]<<endl;break;}
    }
    return 0;
}
