#include <iostream>
using namespace std;
int main()
{
    long n, i=0, d[20];
    long m, x;
    cin>>n>>m;
    x=m;
    while (x>0)
    {
          d[i]=x%3; if (d[i]==2)d[i]=-1;
          x=(x-d[i])/3; i++;
    }  
    cout<<m;
    x=1;
    for (int i=0;i<n;i++)
    {
          if (d[i]==-1)cout<<" "<<x;
          x*=3;
    }   
    cout<<endl;
    x=1;
    for (int i=0;i<n;i++)
    {
          if (d[i]==1)
             if (i<n-1)cout<<x<<" ";
             else cout<<x;
          x*=3;
    }   
    cout<<endl;
    return 0;
}
