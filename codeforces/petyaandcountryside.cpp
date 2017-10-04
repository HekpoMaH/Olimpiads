#include<iostream>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1005];
int n,res,mx;
int check(int pos)
{
    int br=1,pos1=pos-1;
    while(pos1>=1)
    {
        if(a[pos1]>a[pos1+1])break;
        pos1--;
        br++;
    }
    int pos2=pos+1;
    while(pos2<=n)
    {
        if(a[pos2]>a[pos2-1])break;
        pos2++;
        br++;
    }
    return br;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        res=check(i);
        if(res>mx)mx=res;
    }
    cout<<mx<<endl;
    return 0;
}