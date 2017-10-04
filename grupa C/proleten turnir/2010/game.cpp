#include<iostream>
#include<queue>
using namespace std;
queue<int> a;
long long n,bn=1,br,br2,bn2,t,p;
int main()
{
  cin>>n;
  for(int i=0;i<2*n;i++)bn*=2;
  for(long long i=0;i<bn;i++){cin>>t;a.push(t);}
  bn2=bn;
  bn2/=2;
  while(a.size()>1)
  {
    //cout<<bn2<<" "<<br2<<endl;
    if(br2==bn2){br++;bn2/=2;br2=0;}
    br2++;
    t=a.front();
    a.pop();
    p=a.front();
    a.pop();
    if(br%2==1)
    {
      if(p>t)a.push(p);
      else a.push(t);
    }
    else
    {
      if(p<t)a.push(p);
      else a.push(t);
    }
    //cout<<a.back()<<endl;
    //cout<<"br2="<<br2<<endl;
    //for(int i=0;i<bn2;i++)cout<<a[br2][i]<<" ";
    //cout<<endl;
  }
  cout<<a.front()<<endl;
  return 0;
}
/*
2
10 15 27 14 12 8 0 30 60 20 9 11 23 31 35 17
*/
