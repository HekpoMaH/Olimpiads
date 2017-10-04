#include<iostream>
using namespace std;
int n,kula1,kula2,kula3,kula4,ost,mn=101;
int main()
{
  cin>>n;
  while(n>0)
  {
    if(n>0){kula1++;n--;}
    if(n>0){kula2++;n--;}
    if(n>0){kula3++;n--;}
    if(n>0){kula4++;n--;}
  }
  if(kula1+kula2<mn)mn=kula1+kula2;
  if(kula2+kula3<mn)mn=kula2+kula3;
  if(kula3+kula4<mn)mn=kula3+kula4;
  if(kula4+kula1<mn)mn=kula4+kula1;
  cout<<mn<<endl;
  return 0;
}
