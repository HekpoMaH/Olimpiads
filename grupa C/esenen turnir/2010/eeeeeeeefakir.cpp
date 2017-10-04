#include<iostream>
//#include<cmath>
//#include<cstring>
//#include<math.h>
//#include<algorithm>
using namespace std;
int a,mn=505;
long sum=0;
int main()
{
  for(int i=0;i<4;i++){cin>>a;if(a<mn)mn=a;sum+=a;}
  //sort(a,a+4);
  sum-=mn;
  sum++;
  cout<<sum<<endl;
  return 0;
}
