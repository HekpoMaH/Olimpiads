#include<iostream>
using namespace std;
//interval trees
int it[100],a[100];
int idx[100],t,x,y,q;
int n;
void crt(int k,int l,int r)
{
    if(l==r)
    {
        //it means that its a leaf
        it[k]=a[l];
        //it[leaf]=a[left/righ] both are possible
        idx[l]=k;
        //and the index= the number of the node
        //its the end so we return
        return;
    }
    //we go left and right
    crt(k*2,l,(l+r)/2);
    crt(2*k+1,(l+r)/2+1,r);
    it[k]=it[k*2]+it[k*2+1];
    //we uderstand this, dont we?
}
int sum(int k,int l,int r,int ql,int qr)
{
    int s=0;
    if(ql<=l&&r<=qr)return it[k];//the leaf is inside the query
    if(!(ql>(l+r)/2||l>qr))s+=sum(k*2,l,(l+r)/2,ql,qr);//if we need to go left we go left
    if(!(ql>r||(l+r)/2+1>qr))s+=sum(2*k+1,(l+r)/2+1,r,ql,qr);//the same... almost xD
    return s;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    //create the interval tree
    //i like the new color of the comments <3
    crt(1,1,n);
    //left=1,right=1,nuber of the node= 1
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int t,x,y;
        cin>>t>>x>>y;
        if(t==1)
        {
            //one for adding, two for sum
            int p=idx[x];//p=the number of leaf'
            while(p!=0)//up to th3 r00t
            {
                it[p]+=y;
                p/=2;
            }
        }
        else cout<<sum(1,1,n,x,y)<<endl;//number of the node, left,right, query left&right
    }
}
