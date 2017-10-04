#include <iostream>
using namespace std;

int main ()
{
    int a,b,c;
    char s;
    cin>>a>>b>>c;
    cin>>s;
    for (b=b*a;b>=1;b--) {
          cout<<s<<endl;
          for (c=c;c>=1;c--) {
              cout<<s; } }
    for (c=c*a+1;c>=1;c--) {
        cout<<s;
        }
    return 0;
}
