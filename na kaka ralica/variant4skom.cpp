#include<iostream>//biblioteki
using namespace std;
int a[]={1,2,3,4,5,6};//deklarirane
int b[]={-3,0,3,6,9,12};//deklarirane
int main()
{
  cout<<" a | b | x"<<endl;
  for(int i=0;i<6;i++)//cikal koito vzema a=1,2,3..
  {
    for(int j=0;j<6;j++)//cikal koito vzema b=-3...
    {
      cout<<" "<<a[i]<<" |";//izvejdame a;
      if(b[j]>=0&&b[j]<10)cout<<" ";//4rez TOZI IF podrejdame tablicata redovete da sa e to4no edna pod druga
      cout<<b[j]<<" |";//izvejdame b
      cout<<3*a[i]*b[j]*b[j]+a[i]*b[j] -3*a[i]*a[i]<<endl;//izvejdame x
    }
  }
  system("pause");
  return 0;
}
