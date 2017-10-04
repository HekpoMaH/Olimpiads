#include<iostream>
#include<algorithm>
using namespace std;
int a[6000],n,s;

int main()
{
 cin>>s>>n;   
  for(int i=0; i<n; i++)
   cin>>a[i];
   sort(a,a+n);
   
    return 0;  
    }
