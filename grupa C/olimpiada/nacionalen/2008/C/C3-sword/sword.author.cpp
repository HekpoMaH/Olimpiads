#include<string>
#include<iostream>
#include<stack>
using namespace std;
int sword(string &s,int n)
{
    stack<char> st;
    int i,l, d='a'-'A';
    char ch;
    for(i=0;i<n;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')s[i]+=d;
        l=0;
        if(!st.empty())
        {
            ch=st.top();
            if(s[i]==ch){st.pop();l=1;}
        }
        if(!l) st.push(s[i]);
    }
    return (st.empty());
}
int main()
{
    string s, ms; 
    int md =0,d ;
    while(cin>>s)
    {
        d=s.size();
        if(sword(s,d))
            if(d>md)
            {
                md=d;
                ms=s;
            }
    }
    cout<<ms<<endl;
}
