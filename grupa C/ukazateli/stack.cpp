#include<iostream>
using namespace std;
struct st
{
    int inf;
    st *next;
};
int x,n;
st *pbeg=0;
int main()
{
    cin>>n;
    st *q=0;
    //insert element
    for(int i=0;i<n;i++)
    {
        cin>>x;
        q=new st;
        q->inf=x;
        if(i>0)q->next=pbeg;
        if(i==0)q->next=0;
        pbeg=q;
    }
    //cout<<pbeg->inf<<endl;
    //delete element
    while(pbeg)
    {
        q=pbeg;
        cout<<q->inf<<endl;
        pbeg=q->next;
        delete q;
    }
    return 0;
}