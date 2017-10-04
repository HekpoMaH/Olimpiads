#include<iostream>
#include<string>
#include<stack>
using namespace std;
string s,s1;
int sz;
stack<char> ss;
char o;
int prioritet(char ch)
{
    if(ch=='(')return 1;
    if(ch=='+')return 2;
    if(ch=='-')return 2;
    if(ch=='*'||ch=='/')return 3;
    return -1;
}
void solve(string ss2)
{
    stack<double> st;
    double x,y;
    int sz2=ss2.size();
    for(int i=0;i<sz2;i++)
    {
        if(ss2[i]>='0'&&ss2[i]<='9')st.push((double)(ss2[i]-'0'));
        else
        {
            x=st.top();
            st.pop();
            y=st.top();
            st.pop();
            swap(x,y);
            if(ss2[i]=='+')x+=y,st.push(x);
            if(ss2[i]=='-')x-=y,st.push(x);
            if(ss2[i]=='*')x*=y,st.push(x);
            if(ss2[i]=='/')x/=y,st.push(x);
        }
    }
    cout<<st.top()<<endl;
}
int main()
{
    cin>>s;
    sz=s.size();
    for(int i=0;i<sz;i++)
    {
        if(s[i]=='(')ss.push(s[i]);
        else
        {
            if(s[i]>='0'&&s[i]<='9')s1+=s[i];
            else
            {
                if(s[i]==')')
                do
                {
                    o=ss.top();
                    ss.pop();
                    //cout<<"o="<<o<<endl;
                    if(o!='(')s1+=o;
                }while(o!='(');
                else
                {
                    while(!ss.empty()&&prioritet(o=ss.top())>prioritet(s[i]))
                    {
                        //cout<<"o="<<o<<endl;
                        ss.pop();
                        s1+=o;
                    }
                    ss.push(s[i]);
                }
            }

        }
    }
    cout<<s1<<endl;
    while(!ss.empty())
    {
        o=ss.top();
        ss.pop();
        s1+=o;
    }
    solve(s1);
    return 0;
}
//((5+4)*3-9*(7-2))*6+3*9
