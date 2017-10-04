#include<iostream>
#include<stack>
#include<vector>
using namespace std;
stack<int> st;
stack<int> cst;
int v[100][100];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a][b]=v[b][a]=1;
    }
    st.push(1);
    while(!st.empty())
    {
        int tp=st.top(),l=0;
        for(int i=1;i<=n;i++)if(v[tp][i]==1)
        {
            v[tp][i]=v[i][tp]=0;
            l=1;
            st.push(i);
            break;
        }
        if(l==0)
        {
            st.pop();
            cst.push(tp);
        }
    }
    while(!cst.empty())
    {
        cout<<cst.top()<<" ";
        cst.pop();
    }
    cout<<endl;
}
/*
8 12
1 2
2 3
2 5
3 4
3 5
3 7
4 2
5 3
5 6
6 3
7 8
8 1
*/
