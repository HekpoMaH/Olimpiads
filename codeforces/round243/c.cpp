#include<bits/stdc++.h>
using namespace std;
int n,a[1000],k,mx=-1000*1000-100,l,r,ps[1000],sum;
void qchek(int l,int r)
{
    vector<int> v;//V fot Vendetta
    vector<int> v2;
    int sum=0,mxel=-1009,fl=0,uk1=0;
    v.clear();
    for(int i=1;i<l;i++)v.push_back(a[i]);
    for(int i=r+1;i<=n;i++)v.push_back(a[i]);
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i=l;i<=r;i++)
    {
        v2.push_back(a[i]);
    }
    int uk2=0;
    for(int i=0;i<k&&i<v.size();i++)v2.push_back(v[i]);
    sort(v2.begin(),v2.end());
    reverse(v2.begin(),v2.end());
    for(int i=0;i<r-l+1;i++)sum+=v2[i];
    if(sum>mx)
    mx=sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){cin>>a[i];}
    //sort(a+1,a+n+1);

    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            qchek(i,j);
        }
    }
    cout<<mx<<"\n";
}
