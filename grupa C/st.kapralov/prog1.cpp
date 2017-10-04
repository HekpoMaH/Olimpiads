#include<iostream>
#include<vector>
using namespace std;
vector<int> a;
int n;
int main()
{
  cin>>n;
  int x;
  for(int i=0;i<n;i++){cin>>x;a.push_back(x);}
  n=a.size();
  for(int x: a)cout<<x<<endl;
  return 0;
}
