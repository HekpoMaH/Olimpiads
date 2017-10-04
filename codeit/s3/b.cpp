#include<bits/stdc++.h>
using namespace std;
const int mit=2009,maxn=100009;
//int it[mit];
int a[maxn],b[maxn];
int n;
/*void up(int pos)
{
    while(pos<=mit)
    {
        it[pos]++;
        pos+=pos&(-pos);
    }
}
int get(int pos)
{
    int re=0;
    int idx=mit;
    while(idx>=1)
    {
        re+=it[pos];
        idx-=idx&(-idx);
    }
    idx=pos;
    while(idx>=1)
    {
        re-=it[pos];
        idx-=idx&(-idx);
    }
    return min(1,re);
}*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream fin("seq.in");
    ofstream fout("seq.out");
    long long ans=0;
    fin>>n;
    for(int i=1;i<=n;i++)fin>>a[i],b[i]=a[i];
    sort(b+1,b+n+1);
    int p=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==b[p])p++;
    }
    p--;
    fout<<n-p<<"\n";
}
