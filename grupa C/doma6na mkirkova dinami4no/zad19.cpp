#include<fstream>
#include<iostream>
using namespace std;
int a[102][122],m,n;
int main()
{
  ifstream fin("input.txt");
  fin>>m>>n;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      fin>>a[i][j];
    }
  }
  //b[0][0]=a[0][0];
  for(int i=1;i<m;i++)a[i][0]=a[i-1][0]+a[i][0];
  for(int i=1;i<n;i++)a[0][i]=a[i-1][0]+a[0][i];
  for(int i=1;i<m;i++)
  {
    for(int j=1;j<n;j++)
    {
      a[i][j]=max(a[i-1][j],a[i][j-1])+a[i][j];
    }
  }
  ofstream fout("output.txt");
  fout<<a[m-1][n-1]<<endl;
  return 0;
}
