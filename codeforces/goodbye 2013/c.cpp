#include<bits/stdc++.h>
using namespace std;
struct stud
{
    int rat,idx;
};
stud a[300009];
int n;
int nrat;
bool cmp(stud x,stud y)
{
    return x.rat<y.rat;
}
bool cmp2(stud x,stud y)
{
    return x.idx<y.idx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    a[0].rat=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].rat;a[i].idx=i;
    }
    nrat=0;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(a[i].rat>nrat)nrat=a[i].rat;
        a[i].rat=nrat;
        nrat++;
    }
    sort(a+1,a+n+1,cmp2);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i].rat<<" ";
    }
    cout<<endl;
}
