#include<iostream>
using namespace std;
int a[1000000],b[1000000],c[2000];
int main()
{
    int i,max=0,m,n;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
       cin>>a[i]>>b[i];
       if(a[i]<=n && a[i]>0)
       c[a[i]]++;
       if(b[i]<=n && b[i]>0)
       c[b[i]]++;
       if(c[a[i]]>max && c[a[i]]==1)
       max=c[a[i]];
       else if(c[a[i]]>max && c[a[i]]!=1)
       max=c[a[i]]-1;
       if(c[b[i]]>max && c[a[i]]!=1)
       max=c[b[i]];
       else if(c[b[i]]>max && c[b[i]]!=1)
       max=c[b[i]]-1;
    }
    cout<<max<<endl;
    //system("pause");
}   
                                                                
