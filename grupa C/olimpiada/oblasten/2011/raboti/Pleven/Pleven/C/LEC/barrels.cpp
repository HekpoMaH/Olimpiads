  #include<iostream>
using namespace std;
  long long s,n,ba[1000001],i,j,k[101];
int main()
{
  cin>>s>>n;
  for (i=1;i<=n;i++)
  {
    cin>>k[i];
  }
  ba[0]=1;
  sort(k+1,k+n+1);
  for (i=1;i<=n;i++)
  {
    for (j=0;j<=s;j++)
    {
      if (ba[j]>0) {if (ba[j+k[i]]==0 || ba[j+k[i]]>ba[j]+1) {ba[j+k[i]]=ba[j]+1;}}
    }
  }
  cout<<ba[s]-1<<endl;
  return 0;
}
