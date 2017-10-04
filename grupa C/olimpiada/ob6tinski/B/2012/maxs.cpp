#include<iostream>
#include<iomanip>
using namespace std;
double a;
int main()
{
  cin>>a;
  cout<<setiosflags(ios::fixed)<<setprecision(3)<<a*a<<endl;
  return 0;
}
