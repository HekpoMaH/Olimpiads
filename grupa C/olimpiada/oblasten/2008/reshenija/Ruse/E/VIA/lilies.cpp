#include<iostream>
using namespace std;
int main ()
{
    int a,n,max=0,max2=0,i;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a;
        if (a>max) max=a;
        if (a<max && a>max2) max2=a;
    }
    cout<<(max+max2)+(n-2)<<endl;
    return 0;
}
