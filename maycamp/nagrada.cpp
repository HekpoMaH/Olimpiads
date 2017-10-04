#include<iostream>
#include<queue>
using namespace std;
queue<long long> q;
long long n,t;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    q.push(i+1);
  }
  while(q.size()>1)
  {
    t=q.front();
    q.pop();
    q.pop();
    q.push(t);
  }
  cout<<q.front()<<endl;
  return 0;
}
