#include<iostream>
using namespace std;
int n,k,m,newn,ost,brdet,det;
int main()
{
  cin>>n>>k>>m;
  while(n>k)
  {
    ost=n%k;
    brdet=n/k;
    det+=brdet;
    newn=brdet*(k-m);
    newn+=ost;
    //cout<<"n="<<n<<" newn="<<newn<<" det="<<det<<endl;
    //system("pause");
    n=newn;
  }
  cout<<det<<endl;
  return 0;
}
