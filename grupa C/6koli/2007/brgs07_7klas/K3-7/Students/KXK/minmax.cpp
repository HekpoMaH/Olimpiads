#include<iostream>
using namespace std;
int mini[55],mi=-1,maxi[55],cntr[10],cntrf[10],mx=-1,k,a[55],n,e[55];
bool found=false;
void minf(int m)
{
    int i,j;
    if(found==true) return;
    if(m==k-1)
    {
        int sum=0;
        for(j=0;j<m;j++)
        sum+=e[j];
        for(i=0;i<n;i++)
        {
            bool can=true;
            if(cntrf[a[i]]+1>cntr[a[i]]) can=false;
            if (can==true)
            {
                sum+=a[i];
                if(sum%3==0)
                {
                    e[m]=a[i];
                    mi=m+1;
                    for(i=0;i<=m;i++)
                    mini[i]=e[i];
                    found=true;
                    return;
                }
            }
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            bool can=true;
            if(cntrf[a[i]]+1>cntr[a[i]]) can=false;
            if(can==true)
            {
                e[m]=a[i];
                cntrf[a[i]]++;
                minf(m+1);
                cntrf[a[i]]--;
            }
        }
    }
    return;
}       
void maxf(int m)
{
    int i,j;
    if(found==true) return;
    if(m==k-1)
    {
        int sum=0;
        for(j=0;j<m;j++)
        sum+=e[j];       
        for(i=n-1;i>=0;i--)
        {
            bool can=true;
            
            if(cntrf[a[i]]+1>cntr[a[i]]) can=false;
            if (can==true)
            {
                sum+=a[i];
                if(sum%3==0)
                {
                    e[m]=a[i];
                    mx=m+1;
                    for(i=0;i<=m;i++)
                    maxi[i]=e[i];
                    found=true;
                    return;
                }
            }
        }
    }
    else
    {
        for(i=n-1;i>=0;i--)
        {
            bool can=true;
            if(cntrf[a[i]]+1>cntr[a[i]]) can=false;
            if(can==true)
            {
                e[m]=a[i];
                cntrf[a[i]]++;
                maxf(m+1);
                cntrf[a[i]]--;
            }
        }
    }
    return;
}  
int main()
{
    string c;
    int i,j;
    cin>>c;
    n=c.size();
    for(i=0;i<n;i++)
    {
        a[i]=(int)c[i]-48;
        cntr[a[i]]++;
    }
    cin>>k;
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        if(a[i]==0) continue;
        e[0]=a[i];
        cntrf[e[0]]++;
        minf(1);
        cntrf[e[0]]--;
    }
    found=false;
    for(i=0;i<10;i++)
    cntrf[a[i]]=0;
    for(i=n-1;i>=0;i--)
    {
        if(a[i]==0) continue;
        e[0]=a[i];
        cntrf[e[0]]++;
        maxf(1);
        cntrf[e[0]]--;
    }
    if(mi==-1) cout<<-1;
    else
    {
        for(i=0;i<mi;i++)
        cout<<mini[i];
        cout<<' ';
        for(i=0;i<mi;i++)
        cout<<maxi[i];
    }
    cout<<'\n';
    return 0;
}

    
