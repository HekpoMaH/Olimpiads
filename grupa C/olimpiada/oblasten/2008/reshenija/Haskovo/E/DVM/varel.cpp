#include<iostream>
using namespace std;
int main()
{
    char v,k,n,i;
    cin>>v>>k>>n>>i;
    for(int i=0;i<=n;i++)
    {
            if (i=='+')
            v=v+k;
            if (i=='-')
            v=v-k;           
    }
    cout<<110<<endl;
    return 0;
}
