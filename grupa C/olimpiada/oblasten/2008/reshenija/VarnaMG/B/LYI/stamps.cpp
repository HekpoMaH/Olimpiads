#include <iostream>
using namespace std;

int min=5000,timer=0;
int s,n;
int a[3001];
    
int main ()
{
    cin>>s>>n;
    for(int i=0;i<n;i++)
      cin>>a[i];
    sort(a,a+n);
    int br=0;
    for(int j=n-1;j>=0;j--)
      {
            br+=(s/a[j]);
            s%=a[j];
      }
    cout<<br<<endl;
    return 0;
}
