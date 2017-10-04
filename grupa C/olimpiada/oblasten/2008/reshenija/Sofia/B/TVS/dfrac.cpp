#include <iostream>
using namespace std;
int main()
{
    long int n,m;
   long long int k,p,i;
    cin>>n>>m>>k>>p;
    i=0;
    while(i!=k-1)
    { n=(n*10)%m;i++;}
    for(int i=k;i<k+p;i++)
     {       cout<<(n*10)/m;
            n=(n*10)%m;
     }        
     cout<<endl;
    return 0;
}
