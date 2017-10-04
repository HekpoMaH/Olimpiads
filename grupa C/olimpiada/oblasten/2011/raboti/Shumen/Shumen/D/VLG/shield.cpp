#include <iostream>
using namespace std;
int main()
{
    int n,a1[128],a2[128],i,m1,m2,l=0,mn,mn2,j;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a1[i];
    for(i=0;i<n;i++)
    cin>>a2[i];
    m1=a1[0];
    if(a1[n-1]>m1)m1=a1[n-1];
    m2=a2[0];
    if(a2[n-1]>m2)m2=a2[n-1];
    for(i=0;i<n;i++)
    if(!((a1[i]+a2[i])>=(m1+m2))){l=1;break;}
    if(l==0)cout<<m1+m2<<endl;
    else
    {
        l=0;
        mn=a1[0];
        if(a1[n-1]<mn)mn=a1[n-1];
        for(i=0,j=n-1;i<n,j>=0;i++,j--)
        if((a1[i]+a2[j])<(mn+m2)){l=1;break;}
        if(l==0)
        cout<<mn+m2<<endl;
        else
        {
            mn2=a2[0];
            if(a2[n-1]<mn2)mn2=a2[n-1];
            cout<<m1+mn2<<endl;
        }
    }
    return 0;
}
