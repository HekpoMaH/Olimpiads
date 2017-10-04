#include<iostream>
#include<algorithm>
using namespace std;
int a[1000009],b[2000009];
int n;
long long bri;
void upd(int idx)
{
    while(idx<=2000009)
    {
        b[idx]++;
        idx+=(idx)&(-idx);
    }
}
int get(int idx)
{
    int re=0;
    while(idx!=0)
    {
        re+=b[idx];
        idx-=(idx)&(-idx);
    }return re;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        upd(a[i]);
        bri+=get(a[i]-1);
    }
    cout<<bri<<endl;
}
/*
7
4 2 7 1 5 6 3
*/

