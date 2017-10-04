#include<iostream>
#include<string>
using namespace std;
string reda;
int n,k=0;
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    reda="";
    for(int j=1;j<=n-i;j++)reda+=" ";
    reda+="*";
    for(int j=1;j<=k;j++)
    {
      reda+=" ";reda+="*";
    }
    k++;
    cout<<reda<<endl;
  }
  return 0;
}
