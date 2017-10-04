#include <iostream>
#include <cstdlib>
#include<math.h>
#include<stdlib.h>
using namespace std;

int main()
{
double a, b;
double k , p;
cin >> a >> b;
cin >> k >> p;

double S;
S=a/b;

int z;
z=S*(pow(10,k));
z=z%10;
S=S*pow(10,k);



cout << z;

for(int i=2; i<p+1; i++)
{
        z=S*10;
        z=z%10;
        cout<<z;
        S=S*10;
        
        
        }    
    
    

    system("PAUSE");
    return EXIT_SUCCESS;
    
}
