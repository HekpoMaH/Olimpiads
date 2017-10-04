#include<iostream>
#include<vector>
using namespace std;
int n;
vector<unsigned> st;
long long x,sz;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x>0)st.push_back(x);
        if(x==0)
        {
            sz=st.size();
            for(int i=0;i<sz;i++)
            {
                st.push_back(st[i]);
            }
        }
        if(x==-1)
        {
            cout<<st[st.size()-1]<<endl;
            st.pop_back();
        }
    }
    return 0;
}
