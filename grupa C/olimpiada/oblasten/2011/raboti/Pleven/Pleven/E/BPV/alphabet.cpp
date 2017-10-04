#include <iostream>

using namespace std;

int main()
{
    int n,m,i;
    char a[80];
    cin>>n>>m;
    while('a'!=m)
    cin.getline(a,80,'.');
    if(a[0]==65+n && a[80]==97-n)
    {if('a'==n)
    cout<<"win"<<" "<<i<<endl;
    else
    cout<<"lose"<<endl;}

  return 0;
}
