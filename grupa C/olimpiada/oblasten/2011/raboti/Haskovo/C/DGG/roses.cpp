#include<iostream>
using namespace std;
long long m,n,s,mx,a[1008][1008],s1;
long long k;
int main()
{
  ios::sync_with_stdio(false);
  cin>>m>>n>>k;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>a[i][j];s1+=a[i][j];
    }
  }
  long long kr2,kr;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      kr=i+k-1;
      kr2=j+k-1;//cout<<kr<<" "<<kr2<<" "<<k<<" "<<i<<" "<<j<<endl;
      if(kr<=m-1&&kr2<=n-1)
      {
        s=0;
        for(int d=i;d<=kr;d++)
        {
          for(int f=j;f<=kr2;f++)
          {
            s+=a[d][f];
          }
        }//cout<<s<<endl;
        if(s>mx)mx=s;
      }

    }
  }
  cout<<s1-mx<<"\n";
  return 0;
}
