#include<iostream>
using namespace std;
int n,m,all,s[1000],r=-1;
int j,k;
void prd(int n,int a[],int &j)
{
    int i=2;
    while(i<=n)
    {
        if(n%i==0)
        {
            a[j]=i;
            j++;
            n/=i;
        }
        else i++;
    }
}
int main()
{
    int a[1000],b[1000],ans=1;
    cin>>n;
    m=n;
    for(int i=2;i*i<=n;i++)
    {
        if(m%i==0)
        {
            r++;
            while(m%i==0)
            {
                s[r]++;
                m/=i;
            }
            all+=s[r];
        }
    }
    if(m!=1){r++;s[r]=1;all+=s[r];}
    for(int i=2;i<=all;i++)prd(i,a,j);
    for(int i=0;i<=r;i++)
    {
        for(int p=2;p<=s[i];p++)prd(p,b,k);
    }
    //for(int i=0;i<j;i++)cout<<"a["<<i<<"]="<<a[i]<<endl;
    //for(int i=0;i<k;i++)cout<<"b["<<i<<"]="<<b[i]<<endl;
    for(int i=0;i<j;i++)
    {
        for(int p=0;p<k;p++)
        {
            if(b[p]%a[i]==0)
            {
                b[p]/=a[i];
                a[i]=1;
                break;
            }
        }
    }
    for(int i=0;i<j;i++)ans*=a[i];
    cout<<ans<<endl;
    return 0;
}