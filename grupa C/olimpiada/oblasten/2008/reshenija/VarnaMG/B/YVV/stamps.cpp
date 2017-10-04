#include<iostream>
#include<stdlib.h>
using namespace std;
int ans[32000],s,n,a[5001],used[5001];
void init()
{
        int i,sum=s,brm=0;
        for(i=0;i<n;i++)
        {
            if(sum>a[i])
            {
                used[i]=sum/a[i];
                brm+=used[i];
                sum=sum%a[i];
            }
        }
        ans[0]=brm+sum;
    return; 
}
int getsum()
{
     int i,sum=0;
     for(i=0;i<n;i++)
            sum+=a[i]*used[i];
     return s-sum;
}
int getbr()
{
    int i,br=0;
    for(i=0;i<n;i++)
            br+=used[i];
    return br;
}
int check()
{
    int i;
    for(i=0;i<n;i++)if(used[i])return 0;
    return 1;
}  
int main()
{
    int i,j,min=5001,mini=0;
    cin>>s>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        min=a[i];
        mini=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]>min)
            {
                min=a[j];
                mini=j;
            }
        }
        swap(a[i],a[mini]);
    }
    n--;
    init();
    int sum,bra=1;
    while(1)
    {
        used[n-1]=0;
        if(check()||bra>32000)break;
        for(i=n;i>=0;i--)
            if(used[i]!=0)
            {
                used[i]--;
                sum=getsum();
                break;
            }
        for(j=i+1;j<n;j++)
        {
            if(sum>a[j])
            {
                used[j]=sum/a[j];
                sum=sum%a[j];
            }
        }
        ans[bra]=getbr()+sum;
        bra++;
    }
    min=5002;
    for(i=0;i<bra;i++)
        if(ans[i]<min)min=ans[i];
    cout<<min<<endl;
    return 0;
}
    
        
    
    
            
        
    
        
                    
