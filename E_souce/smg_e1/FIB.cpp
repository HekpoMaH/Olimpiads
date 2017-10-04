#include <iostream>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int i,bef_1=1,bef_2=1;
    if (n==1) { cout<<"1"<<endl; }
    if (n==2) { cout<<"1"<<endl; }
    if (n!=1&&n!=2) {
    n=n-3;
    for (n;n>=0;n--) { 
          i=bef_1+bef_2;
          bef_1=bef_2;
          bef_2=i;
          }
          cout<<i<<endl;
          }
          return 0;
          }
           
    
