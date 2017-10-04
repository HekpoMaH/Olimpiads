//Just like CS bro
#include<bits/stdc++.h>
using namespace std;
int n;
string s;
set<char> ch;
int l1,l2,l3;
int main()
{
    cin>>s;
    if(s.size()<5){cout<<"Too weak"<<endl;return 0;}
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')l1=1;
        if(s[i]>='a'&&s[i]<='z')l2=1;
        if(s[i]>='A'&&s[i]<='Z')l3=1;
        ch.insert(s[i]);
    }
    if(l1&&l2&&l3)
    {
        cout<<"Correct"<<endl;return 0;
    }
    cout<<"Too weak"<<endl;
}
