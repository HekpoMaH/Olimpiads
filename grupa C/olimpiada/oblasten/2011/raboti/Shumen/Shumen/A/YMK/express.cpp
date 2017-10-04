#include<iostream>
#include<stack>
using namespace std;

int count(string s)
{
    stack<char> zn;
    stack<long long> ch;
    int sz;
    char z;
    long long w
    sz=s.size();
    ch.push((long long)(s[0]-'0'));
    for(int i=1;i<sz;i++)
    {
        if(s[i]=='+' || s[i]=='(')
            zn.push(s[i]);
        if(s[i]>='0' && s[i]<='9')
           if(zn.top()=='*')
           {
               zn.pop();
               w=ch.top();
               ch.pop();
               w=w*((long long)(s[i]-'0'));
               ch.push(w);
           }
           else
                ch.push(((long long)(s[i]-'0')));
        if(s[i]=')')
        {
            w=ch.top();
            ch.pop()
            while(zn.top()!='(')
            {
                z=st.top();
            }
        }
    }

}

int main()
{


    return 0;
}
