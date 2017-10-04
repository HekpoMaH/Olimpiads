#include <iostream>
using namespace std;
struct 
    {
     string a;
     }pl[1010];
int main()
{
int i,j;
int m,n;
string x;
cin>>m>>n;
for(i=0;i<m;i++)
    {
     cin>>x;
    pl[i].a+=x;
    }
return 0;
}
