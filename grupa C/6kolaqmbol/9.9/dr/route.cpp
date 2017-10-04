#include<iostream>
#include<string>
using namespace std;
string s;
int n,a[256][256],b[256][256];
char path[256][256];
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>s;
    for(int j=0;j<s.size();j++)a[i][j]=s[j]-'0';
  }
  b[0][0]=a[0][0];
  for(int i=1;i<n;i++)
  {
    b[i][0]=b[i-1][0]+a[i][0];
    b[0][i]=b[i-1][0]+a[0][i];
  }
  for(int i=1;i<n;i++)
  {
    for(int j=1;j<n;j++)
    {
      b[i][j]+=min(b[i-1][j],b[i][j-1])+a[i][j];
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      path[i][j]='-';
    }
  }
  //cout<<b[n-1][n-1]<<endl;
  int indi=n-1,indj=n-1;
  while(indi>=0&&indj>=0)
  {
    if(indi>-1&&indj>-1){path[indi][indj]='#';}
    //cout<<endl;
    //cout<<indi<<" "<<indj<<endl;
    if(indi==0){indj--;}
    else if(indj==0){indi--;}
    else if(indi!=0&&indj!=0)
    {
      if(b[indi-1][indj]<b[indi][indj-1])indi--;
      else indj--;
    }
    //cout<<indi<<" "<<indj<<endl;
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)cout<<path[i][j];
    cout<<endl;
  }
  return 0;
}
