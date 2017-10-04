#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int tree[530000];
int n,m,lenq,pl[20009];
char q[200009],let[20009];
int get(int root,int l,int r,int s)
{
    if(l==r)
    {
        return root;
    }
    if(tree[2*root]>=s)return get(root*2,l,(l+r)/2,s);
    else return get(root*2+1,(l+r)/2+1,r,s-tree[root*2]);

}
void update(int o,int s)
{
    while(o>0)
    {
        tree[o]+=s;
        o/=2;
    }
}
void solve()
{
    int s;
    for(char c='a';c<='z';c++)
    {
        memset(tree,0,sizeof(tree));
        for(int i=0;i<lenq*m;i++)
        {
            if(q[i]==c)update(i+262144,1);
        }
        for(int i=1;i<=n;i++)
        {
            if(let[i]==c)
            {
                s=get(1,1,262144,pl[i]);
                q[s-262144]='!';
                update(s,-1);
            }
        }
    }
    for(int i=0;i<lenq*m;i++)if(q[i]!='!')printf("%c",q[i]);
    cout<<endl;
}
int main()
{
    scanf("%d",&m);
    scanf("%s",&q);
    lenq=strlen(q);
    for(int i=lenq;i<lenq*m;i++)
    {
        q[i]=q[i-lenq];
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d %c",&pl[i],&let[i]);
    solve();
}
