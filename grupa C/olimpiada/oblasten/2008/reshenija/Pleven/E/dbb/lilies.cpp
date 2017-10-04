#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{int n,a,i,s=0,m=20;
cin>>n;
i=1;
while(i<=n)
{cin>>a;
i++;
if(a<m)m=a;
s=s+a;}
cout<<(s-m+1);
//system("PAUSE");
return 0;
}
