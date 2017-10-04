#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct nom
{
    int num;
    string p;
};
nom cm[100005],maf[100005];
int n,m;
bool dn[100005];
bool cmp(nom f,nom s)
{
    if(f.p<s.p)return true;
    if(f.p>s.p)return false;
    if(f.num<s.num)return true;
    return false;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",&cm[i].p);
        cm[i].num=i;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%s",&maf[i].p);
        maf[i].num=i;
    }
    sort(cm+1,cm+n+1,cmp);
    sort(maf+1,maf+m+1,cmp);
    //for(int i=1;i<=n;i++)cout<<cm[i].p<<endl;
    //cout<<endl;
    //for(int i=1;i<=m;i++)cout<<maf[i].p<<endl;
    int i=1,j=1;
    while(i<=n&&j<=m)
    {
        //cout<<cm[i].p<<" "<<maf[j].p<<endl;
        if(cm[i].p==maf[j].p)
        {
            dn[maf[j].num]=true;
            j++;
        }
        else if(cm[i].p<maf[j].p){i++;}
        else if(cm[i].p>maf[j].p){j++;}
    }
    for(int i=1;i<=m;i++)
    {
        if(dn[i]==true)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}