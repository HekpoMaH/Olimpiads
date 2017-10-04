#include<iostream>
#include<string>
using namespace std;
int a[300];
string s;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)a[(int)s[i]]++;
    int br=0;
    for(int i=0;i<300;i++)if(a[i]!=0)br++;
    if(br%2==0)cout<<"CHAT WITH HER!"<<endl;
    else cout<<"IGNORE HIM!"<<endl;
    return 0;
}
