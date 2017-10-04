#include<iostream>
using namespace std;
int field[1003][1003];
long long int mx = -1;
long long int og =0;
long long int sb =0;
int main()
{
  int m,n,k;
  cin>>m>>n>>k;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>field[i][j];
    }
  }
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
     sb+=field[i][j];
    }
  }
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      og =0;
      for(int h=i;h<i+k;h++)
      {
        for(int g = j;g<j+k;g++)
        {
         og += field[h][g];
        }
      }

     if(og>mx)
     {
       mx =og;

     }
    }
  }
  cout<<sb-mx<<endl;
  return 0;
}
