#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int p;
    long int a,b,k;
    double l,c
    ;
    cin >> a >> b >> k >> p;
    l=a/b;
    for(int i=0; i<=k+p; i++)
    {       
            l=l*10;
            c=l;
            if(i > k)
            {
                 
                 cout<< c%10;
            }
    }
    system("pause");
    return 0;
}
