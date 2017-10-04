#include <iostream>
using namespace std;
int main()
{
    int s,n,p,max,max1,i,j,s1;
    int a[3000];
    cin>>s>>n;
    for( i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n-1;i++)
                      for(j=i;j<n;j++)
                      if(a[i]>a[j])
                      {
                                   p=a[i];
                                   a[i]=a[j];
                                   a[j]=p;
                      }
    i=n-1;max=5001;                  
    while(i>=0)
    {
             j=i;s1=s;max1=0;  
               while(j>=0)
               {p=s1/a[j];
               max1=max1+p;
               s1=s1-(p*a[j]);
               j--;
               }
             if(max>max1&&max1!=0)
             max=max1;
             i--;
    }
    cout<<max<<endl;           
    return 0;
}
