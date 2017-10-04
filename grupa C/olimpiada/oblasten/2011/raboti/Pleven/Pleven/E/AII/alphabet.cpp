#include <iostream.h>
using namespace std;
char a[90];
int main()
{
int n,m,o=0,ro;
int fl=0;
cin>>n>>m;
while (m>=1)
{
  m--;
  o++;
  cin.getline (a,90,'.');
  if ((a[1]-n)==96) {fl=1;ro=o;}
  if ((a[1]-n)==64) {fl=1;ro=o;}
}
if (fl==0) cout<<"lose"<<endl;
if (fl==1) cout<<"win"<<' '<<ro<<endl;
    return 0;
}