#include<iostream>
using namespace std;
int er[10004],n,j,br,n1;
int main()
{
  cin>>n;er[1]=1;
  n1=n;
  //eratosten
  for(int i=2;i<=10004;i++)
  {
    for(int j=0;j<=10004;j+=i)
    {
      if(i!=j)er[j]=1;
    }
  }

  int i=2,j=n1-2;
  while(i<=j){if(er[i]==0&&er[j]==0)br++;i++;j--;}
  cout<<br<<endl;
  return 0;
}
