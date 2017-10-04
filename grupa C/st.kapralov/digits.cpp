#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int n;
int t[10];
bool cmp(char x,char y)
{
    if(t[x-'0']<t[y-'0'])return true;
    if(t[x-'0']==t[y-'0']&&x>y)return true;
    return false;
}
int main()
{
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++)t[s[i]-'0']++;
    for(int i=0;i<10;i++)t[i]*=(i+1);
    sort(s.begin(),s.end(),cmp);
    cout<<s<<endl;
    return 0;
}
