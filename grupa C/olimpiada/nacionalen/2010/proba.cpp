#include<iostream>
#include<algorithm>
#include<vector>
#define inf 0xDEAD
using namespace std;
vector<int> a;
int main()
{
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  cout<<inf<<endl;
  do
  {
    for(int i=0;i<3;i++)cout<<a[i]<<" ";
    cout<<endl;
    cout<<"np  "<<next_permutation(a.begin(),a.end())<<endl;
  }while(next_permutation(a.begin(),a.end()));
  //cout<<"np  "<<next_permutation(a.begin(),a.end())<<endl;
  return 0;
}
