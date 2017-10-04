#include<iostream>
using namespace std;
int main()
{
    int c1,c2,mini=-1,i,j,a[50],n,s,o,m1,m2=-1,n1,n2=-1;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cin>>s;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        c1=0;
        c2=0;
        for(o=0;o<s/2;o++)
        {
            c1=o;
            if(o!=0)
            c2=(s/(c1*a[i]))/a[j];
            else c2=s/a[j];
            if(c1*a[i]+c2*a[j]==s&&c2+c1<mini)
            {
                mini=c1+c2;
                m1=c1;
                m2=c2;
                n1=a[i];
                n2=a[j];
            }
            if((c1*a[i])+(c2*a[j])==s&&mini==-1)
            {
                mini=c1+c2;
                m1=c1;
                m2=c2;
                n1=a[i];
                n2=a[j];
            }
        }
    }
    if(m2!=0&&m1!=0)
    cout<<mini<<'\n'<<n1<<' '<<m1<<'\n'<<n2<<' '<<m2<<'\n';
    else
    if(m2==0)
    cout<<mini<<'\n'<<n1<<' '<<m1<<'\n';
    else
    cout<<mini<<'\n'<<n2<<' '<<m2<<'\n';
    system("pause");
    return 0;
}
