#include<iostream>
using namespace std;
double sa,sb,p=1;
int k;
int main()
{
  cin>>k;
  for(int i=1;i<=k;i++)
  {
    p*=i;
    sa+=1/p;
    sb+=p;
  }
  cout<<sa<<" "<<sb<<endl;
  return 0;
}
