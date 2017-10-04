//obraten polski zapis
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
enum lexema {op,num,skoba};
struct lex
{
    lexema tp;
    int val;
};
string s;
vector<lex> vi,vp;
int sz,vs,fl;
lex ll;
stack<lex> st;
int prioritet(lex a)
{
    if(a.tp==skoba)return 1;
    if(a.tp==op&&(a.val==1||a.val==2))return 2;
    if(a.tp==op&&a.val==3)return 3;
    return -1;
}
void solve()
{
    stack<lex> sum;
    int ps=vp.size(),x,y;
    for(int i=0;i<ps;i++)
    {
        if(vp[i].tp==num)sum.push(vp[i]);
        if(vp[i].tp==op)
        {
            ll=sum.top();
            x=ll.val;
            sum.pop();
            ll=sum.top();
            y=ll.val;
            swap(x,y);
            sum.pop();
            if(vp[i].val==1)x+=y;
            if(vp[i].val==2)x-=y;
            if(vp[i].val==3)x*=y;
            ll.val=x;
            sum.push(ll);
        }
    }
    cout<<sum.top().val<<endl;
}
int main()
{
    cin>>s;
    sz=s.size();
    for(int i=0;i<sz;i++)
    {
        ll.val=0;
        //cout<<i<<endl;
        if(s[i]=='+')
        {
            ll.tp=op;
            ll.val=1;
        }
        if(s[i]=='-')
        {
            ll.tp=op;
            ll.val=2;
        }
        if(s[i]=='*')
        {
            ll.tp=op;
            ll.val=3;
        }
        if(s[i]=='(')
        {
            ll.tp=skoba;
            ll.val=1;
        }
        if(s[i]==')')
        {
            ll.tp=skoba;
            ll.val=2;
        }
        fl=0;
        while(s[i]>='0'&&s[i]<='9')
        {
            fl=1;
            ll.tp=num;
            ll.val*=10;
            ll.val+=s[i]-'0';
            i++;
            if(i==sz){break;}
        }
        //cout<<ll.val<<endl;
        //return 0;
        if(fl)i--;
        vi.push_back(ll);
    }
    //cout<<s<<endl;
    ll.tp=num;
    //cout<<ll.tp<<endl;
    vs=vi.size();
    for(int i=0;i<vs;i++)
    {
        if(vi[i].tp==skoba&&vi[i].val==1)st.push(vi[i]);
        else
        {
            if(vi[i].tp==num)vp.push_back(vi[i]);
            else
            {
                if(vi[i].tp==skoba&&vi[i].val==2)
                do
                {
                    ll=st.top();
                    st.pop();
                    if(ll.tp!=skoba)vp.push_back(ll);
                }while(ll.tp!=skoba);
                else
                {
                    while(!st.empty()&&prioritet(ll=st.top())>prioritet(vi[i]))
                    {
                        st.pop();
                        vp.push_back(ll);
                    }
                    st.push(vi[i]);
                }
            }
        }
    }
    while(!st.empty())
    {
        ll=st.top();
        st.pop();
        vp.push_back(ll);
    }
    solve();
    return 0;
}
//acm.ro
