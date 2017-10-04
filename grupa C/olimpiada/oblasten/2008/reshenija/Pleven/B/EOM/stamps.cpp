#include<iostream.h>
using namespace std;
long s,n,a[10003],b[10003];
int main()
{ long i,j;
  cin>>s>>n;
  for(i=1;i<=n;i++) cin>>a[i];
  sort(a,a+n+1);
  for(i=1;i<=n;i++)
  { b[a[i]]=1;
    for(j=a[i]+1;j<=s;j++) 
    { if (b[j]>b[j-a[i]]+1 || b[j]==0) b[j]=b[j-a[i]]+1;
    }  
  }
  cout<<b[s]<<endl;
return 0;
}
