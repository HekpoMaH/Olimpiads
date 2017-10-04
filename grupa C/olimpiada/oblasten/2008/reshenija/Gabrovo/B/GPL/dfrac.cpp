#include <iostream>
using namespace std;
long long int i=1;
long long int p;
long long int k;
void dfrac(long int x,long int y)
{
     if(i!=k+p)
     {
               if(i>=k&&i<k+p)
                cout<<x/y;
               x=(x%y)*10;
               i++;
               dfrac(x,y);
     }
}
int main()
{
    long long int a,b;
    cin>>a>>b>>k>>p;
    a=(a%b)*10;
    dfrac(a,b);
    return 0;
}    
    
