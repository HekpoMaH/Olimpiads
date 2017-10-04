#include<bits/stdc++.h>
using namespace std;
int n,a[100090],b[100090],p1,p2,br;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i],a[i]++,b[a[i]]=a[i];if(a[i]==i)p1++;}
    //for(int i=1;i<=n;i++)cout<<b[a[i]]<<" ";cout<<endl;
    //cout<<p1<<endl;
    p2=max(p1,p2);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==i)continue;
        br=1;
        if(a[a[i]]==i)br++;
        p2=max(p1+br,p2);
    }
    p2=max(p2,p1);
    cout<<p2<<endl;
}

