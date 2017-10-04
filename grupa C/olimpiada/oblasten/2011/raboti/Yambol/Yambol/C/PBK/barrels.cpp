#include<iostream>
using namespace std;
long long a[105],m[1000005];
long long s,n;
int main()
{
  long long i,j;
  cin>>s>>n;
  for(i=1;i<=s;i++)
    m[i]=s+1;
  for(i=1;i<=n;i++)
    cin>>a[i];
  sort(a+1,a+n+1);
  i=0;
  while(i<s)
  {
    i++;
    for(j=1;j<i;j++)
      if(m[j]+m[i-j]<m[i])
        m[i]=m[j]+m[i-j];


    for(j=1;j<=n;j++)
      if(i%a[j]==0)
        if(i/a[j]<m[i])
          m[i]=i/a[j];
  }
  cout<<m[s]<<endl;
}
/*
10 7
12 1 11 30 14 2 1 8
*/
