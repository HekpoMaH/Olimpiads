#include<iostream>
#include<string>
using namespace std;
double a[101][101];
int n;
struct teflon
{
  string number;
  int working[11],nw;
  double tax;
};
teflon sldk,friends[102],bb;
int main()
{
  cin>>n;
  int f;
  for(int i=0;i<=n;i++)
  {
    cin>>friends[i].number;
    cin>>friends[i].tax;
    cin>>friends[i].nw;
    for(int i=1;i<=friends[i].nw;i++)
    {
      cin>>f;
      friends[i].working[f]=1;
    }
  }
  cin>>bb.number;