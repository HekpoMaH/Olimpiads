#include<iostream>
using namespace std;
int main ()
{
    long v,k,n,i;
    char c;
    cin>>v;
    cin>>k;
    cin>>n;
    for (i=1;i<=5;i++)
    {
        cin>>c;
        if(c=='+') v=v+k;
        if(c=='-') v=v-k;
    }
    cout<<v<<endl;
    return 0;
}
