#include<iostream>
using namespace std;
long long m[105][105][105],x,i,f;
int main()
{
  cin>>x;
  m[1][1][1]=1;
  i=2;
  while(f==0)
  {
    for(int k=1;k<=i;k++)
    {
      for(int j=1;j<=i;j++)
      {
        m[i][k][j]=m[i-1][k][j]+m[i-1][k-1][j-1]+m[i-1][k-1][j]+m[i-1][k][j-1];
        //cout<<m[i][k][j]<<endl;
        if(m[i][k][j]>x){f=1;break;}
      }
      if(f==1)break;
    }
    /*for(int k=1;k<=i;k++)
    {
      for(int j=1;j<=i;j++)
      {
        cout<<m[i][k][j]<<" ";
      }
      cout<<endl;
    }*/
    //system("pause");
    i++;
    //cout<<m[i][i/2][i/2]<<endl;
    //cout<<i<<endl;
  }
  cout<<i-1<<endl;
  return 0;
}
