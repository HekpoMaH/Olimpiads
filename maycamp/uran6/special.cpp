#include<iostream>
#include<cmath>
using namespace std;
long long m[200][200],a[40000],b[40000],n,brtr,br;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a[i]>>b[i];
    m[a[i]][b[i]]=1;
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(a[i]==a[j]&&m[b[i]][a[i]]==1&&m[b[i]][b[i]]==1)
      {
        br++;
        cout<<abs(a[i]-b[i])*abs(a[i]-b[i])<<endl;
      }
    }
  }
  cout<<br<<endl;
  return 0;
}
