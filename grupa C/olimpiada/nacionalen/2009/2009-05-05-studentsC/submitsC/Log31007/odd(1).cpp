/*
TASK:odd
LANG:C++
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n;
char c;
long long a[1000000],x,t;

void read()
{
     cin>>n;
     for (int i=0;i<n;i++) {
         cin>>a[i];
     }
}

int main()
{
    read();
    sort(a,a+n);
    for (long i=0;i<n;i++) {
        x=a[i];
        t=i;
        while(((i+1)<n) && (a[i+1]==x)) { i++; }
        if(((i-t)+1)%2==1) { cout<<a[i]<<endl; return 0; }
    }
    return 0;
}
