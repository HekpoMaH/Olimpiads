#include<iostream>
#include<string>
#include<stack>
using namespace std;
string s;
stack<char> sk;
stack<int> pos;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            sk.push(s[i]);
            pos.push(i);
        }
        if(s[i]=='[')
        {
            sk.push(s[i]);
            pos.push(i);
        }
        if(s[i]==')')
        {
            if(!sk.empty()&&sk.top()=='(')sk.pop(),pos.pop();
            else sk.push(s[i]),pos.push(i);
        }
        if(s[i]==']')
        {
            if(!sk.empty()&&sk.top()=='[')sk.pop(),pos.pop();
            else sk.push(s[i]),pos.push(i);
        }
    }
    while(!sk.empty())
    {
        s[pos.top()]='0';
        pos.pop();sk.pop();
    }
    //cout<<s<<endl;
    int br1=0,br2=0,mx=0,l=4,r=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='0')br1++;
        if(s[i]=='[')br2++;
        if(s[i]=='0')
        {
            if(br2>mx)
            {
                mx=br2;r=i-1;l=i-br1;
            }br1=0;br2=0;
        }
    }
    if(br2>mx)
            {
                mx=br2;r=s.size()-1;l=s.size()-br1;
            }
    cout<<mx<<endl;
    for(int i=l;i<=r;i++)
    {
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}
