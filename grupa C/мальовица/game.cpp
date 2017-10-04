#include<iostream>
using namespace std;
long long a[19][262164];
long long n,bn=1,br,br2,bn2;
int main()
{
  cin>>n;
  for(int i=0;i<2*n;i++)bn*=2;
  for(long long i=0;i<bn;i++)cin>>a[0][i];
  bn2=bn;
  while(bn2>1)
  {
    br=0;
    br2++;

    for(long long i=0;i+1<bn2;i+=2)
    {

      if(br2%2==0){a[br2][br]=max(a[br2-1][i],a[br2-1][i+1]);
      br++;}
      else{a[br2][br]=min(a[br2-1][i],a[br2-1][i+1]);
      br++;}
    }
    bn2/=2;//cout<<"br2="<<br2<<endl;
    //for(int i=0;i<bn2;i++)cout<<a[br2][i]<<" ";
    //cout<<endl;
  }
  cout<<a[br2][0]<<endl;
  return 0;
}
