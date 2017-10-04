#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
struct sgs
{
    int num,x,y;
};
sgs ots[502];
int child[502],children[502],n;
bool cmp(sgs a,sgs b)
{
    if(a.x>b.x)return true;
    if(a.x<b.x)return false;
    if(a.y>b.y)return true;
    return false;
}
bool ce(sgs a,sgs b)
{
    if(a.x<b.x&&a.y>b.y)return true;
    return false;
}
int mx,mi;
void printpath()
{
    int idx=mi;
    stack<int> res;
    res.push(ots[idx].num);
    while(idx!=child[idx])
    {
        idx=child[idx];
        res.push(ots[idx].num);
    }
    while(!res.empty())
    {
        cout<<res.top()<<" ";
        res.pop();
    }
    cout<<endl;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        children[i]=1;child[i]=i;
        ots[i].num=i;
        cin>>ots[i].x>>ots[i].y;
    }
    sort(ots+1,ots+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(ce(ots[j],ots[i])&&children[i]+1>children[j])
            {
                children[j]=children[i]+1;
                child[j]=i;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(mx<children[i])
        {
            mx=children[i];
            mi=i;
        }
    }
    cout<<mx<<endl;
    printpath();
    return 0;
}