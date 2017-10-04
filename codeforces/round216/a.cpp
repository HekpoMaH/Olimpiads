#include<bits/stdc++.h>
using namespace std;
int n,a[1009];
int m,k,br1,br2;
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)br1++;
        else br2++;
    }
    int izm=0;
    if(br1>m)izm+=br1-m;
    //m=m-(br1-m);
    if(br1<m)k+=m-br1;
    if(br2>k)izm+=br2-k;
    cout<<izm<<endl;
}
