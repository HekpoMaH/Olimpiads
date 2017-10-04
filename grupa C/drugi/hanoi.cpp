#include<iostream>
using namespace std;
void hanoi(int source,int target,int help,int k)
{
  if(k==1)cout<<source<<" "<<target<<endl;
  else
  {
    hanoi(source,help,target,k-1);
    cout<<source<<" "<<target<<endl;
    hanoi(help,target,source,k-1);
  }
}
int main()
{
  int n;
  cin>>n;
  hanoi(1,3,2,n);
  return 0;
}
