#include<iostream>
using namespace std;
int a[10000][10000];
int group[10000],n,k,p;
int main()
{
  cin>>k;
  cin>>n;
  for(int i=1;i<n;i++)
  {
    cin>>p;group[i]=1;
    a[p][i+1]=1;
  }
  group[0]=1;
  cout<<a[7][14]<<endl<<endl;
  for(int i=n-2;i>=0;i--)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(a[i][j]==1){group[i]++;cout<<i<<" "<<j<<endl;}

      //system("pause");
      if(group[i]>=k)
      {
        cout<<i<<" gr"<<group[i]<<endl;
        group[i]=0;
        for(int f=1;f<=n;f++)
        {
          a[i][f]=0;
        }
        break;
      }

    }
  }
  cout<<endl;
  return 0;
}
