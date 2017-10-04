#include <iostream>
using namespace std;
int main ()
{
    int N,a[7],b,i,min,max,k,l;
    cin>>N;
    cin>>a[i];
    for (i=0;i<N;i++)
    {
        max=0;
        for (i=0;i<N;i++)
        {
            l=a[i+1];
            if (l>max)
            {
                max=l;
            }
        }
    }     
        cout<<max+1;
     system ("pause");
     return 0;
}                    
