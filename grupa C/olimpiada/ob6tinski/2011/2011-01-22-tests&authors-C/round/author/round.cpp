#include<iostream>
using namespace std;

int k, m;
long long st=1, res=0;

int main()
{
    cin>>k;
    m=k-1;
    while (m!=0) 
    {
          res+=6*st*(m%2);
          st*=10; m/=2;
    }
    cout<<res<<endl;
}


