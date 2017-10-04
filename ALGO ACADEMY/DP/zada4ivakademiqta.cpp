#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1],l=0,l1=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    int br=1,br2=0;
    if(a[1]>=k)cout<<2<<endl;
    else if(a[2]>=k)cout<<2<<endl;
    else
    {
        br=3;
        br2=3;
        for(int i=3;i<n;i=i+2)
        {
            if(a[i]>=k){l1=1;break;}
            if(a[i+1]>=k){l1=1;break;}
            br++;
        }
        for(int i=4;i<n;i=i+2)
        {
            if(a[i]>=k){l=1;break;}
            if(a[i+1]>=k){l=1;break;}
            br2++;
        }
        if(l1==0)br++;
        if(br>br2)cout<<br2<<endl;
        else cout<<br<<endl;
    }
    return 0;
}