#include <iostream>
using namespace std;
double p,q,r;
int main(void)
{
  cin>>p>>q>>r;
  if (p!=r) cout<<0<<endl;
  else {cout.setf(ios::fixed,ios::floatfield);
        cout.precision(4);
        cout<<2*p*(p+q)<<endl;
       }
  return 0;
}
