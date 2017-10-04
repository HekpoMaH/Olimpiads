#include<bits/stdc++.h>
using namespace std;
string s;
int a[1009];
int br;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i+=2)
    {
        br++;a[br]=s[i]-'0';
    }int n=br;
    sort(a+1,a+n+1);

    for(int i=1;i<n;i++)cout<<a[i]<<"+";cout<<a[n]<<endl;
}
