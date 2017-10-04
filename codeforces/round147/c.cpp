#include<iostream>
#include<cstring>
using namespace std;
int a,b,k;
int er[1000006],sum[1000006];
int main()
{
    cin>>a>>b>>k;
    er[1]=-1;
    for(int i=2;i<=1000000;i++)
    {
        if(er[i]==-1)continue;
        er[i]=1;
        for(int j=i;j<=1000000;j+=i)if(i!=j)er[j]=-1;
    }
    for(int i=2;i<=1000000;i++)
    {
        if(er[i]==1)sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1];
    }
    int l=1,r=b-a+1;
    int mid;
    //cout<<sum[6]-sum[2]<<endl;
    int ans=-1,flag;
    while(l<=r)
    {
        mid=(l+r)/2;flag=0;
        //cout<<mid<<endl;
        for(int i=a;i<=b-mid+1;i++)
        {
            //cout<<i-1<<" "<<mid+i-1<<" "<<sum[i-1]<<" "<<sum[mid+i-1]<<endl;
            if(sum[mid+i-1]-sum[i-1]<k){l=mid+1;flag=1;break;}
        }
        if(flag==0)ans=mid,r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
