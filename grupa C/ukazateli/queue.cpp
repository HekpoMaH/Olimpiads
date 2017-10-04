#include<iostream>
using namespace std;
struct op
{
    int inf;
    op *next;
};
int x,n;
op *pbeg,*pend;
int main()
{
    cin>>n;
    op *q=0;
    //insert element
    for(int i=0;i<n;i++)
    {
        cin>>x;
        q=new op;
        q->inf=x;q->next=0;
        if(!pbeg)pbeg=q;
        else pend->next=q;
        pend=q;
    }
    //cout<<pbeg->inf<<endl;
    //delete element
    while(pbeg)
    {
        q=pbeg;
        cout<<q->inf<<endl;
        if(pbeg==pend)
        {
            pbeg=0;pend=0;
        }
        else pbeg=q->next;
        delete q;
    }
    return 0;
}