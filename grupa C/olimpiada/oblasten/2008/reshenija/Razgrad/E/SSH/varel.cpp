#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
 
int main()
{      
    int V,K,N;
    cin>>V>>K>>N;
    char zn[N];
    if (V <= 1000 && K<=20 && N<=50)
    {
           for (int i=0;i<N;i++)
           {
                cin>>zn[i];
           }
           for (int i=0;i<N;i++)
           {
                 if (zn[i] == '+') V=V+K;
                 else V=V-K;
           }
            cout<<V<<endl;
    }    
    //system ("PAUSE");    
    return 0;
}
