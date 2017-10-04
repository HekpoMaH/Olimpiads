#include<bits/stdc++.h>
using namespace std;
int n;
string s;
stack<char> st;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(!st.empty()&&s[i]==st.top())st.pop();
        else st.push(s[i]);
    }
    if(!st.empty())cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
