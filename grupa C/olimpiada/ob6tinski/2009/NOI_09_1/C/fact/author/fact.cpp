#include<string>
using namespace std;
int max=10000;
int n;
int a[max+1];
int main()
{
  cin>>n;
  int v;
	int j;
  for(int i=2;i<=n;i++)
  {
    v=i;j=2;
	  while(v>1)
	  {
	    while(v%j==0) {v /=j; a[j]++;}
	    j++;
	  }
  }
  int c=0;
  for(int i=1;i<=max;i++) c += a[i];
  cout<<c<<endl;
  return 0;
}

