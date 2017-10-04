#include<iostream>
using namespace std;
int palind_check(int *A,int n,int b)
{
  bool flag=true;
  for(int a=b;a<n/2;a++){if(A[a]==A[n-1-a]&&flag==true){flag=true;}else{flag=false;}}
  if(flag==true&&b==0){cout<<1<<endl<<endl;}
  else{cout<<2<<endl<<2;}
  }

int main()
{
  int n,a;
  cin>>n; int A[n];
    bool flag=true;
    for(a=0;a<n;a++){cin>>A[a];}
    palind_check(A,n,0);
    cout<<endl;
return 0;
  }