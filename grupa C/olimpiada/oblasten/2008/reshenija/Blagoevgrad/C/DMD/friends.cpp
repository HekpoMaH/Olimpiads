#include <iostream>

using namespace std;
int a[2000],n,m,o,x,y;
int main()
{cin>>n>>m;
 for(int i=0;i<m;i++)
 {
         cin>>x>>y;
         a[x]++;
 }
 for(int i=0;i<=n;i++)
 if(a[x]>o) o=a[x];
 cout<<o<<"\n";
    
    
    return 0;
}
