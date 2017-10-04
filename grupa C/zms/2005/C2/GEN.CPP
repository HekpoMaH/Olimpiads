//borland c++3.1
#include<iostream.h>
#include<stdlib.h>
const int n=12;
int main()
{
 cout << n << "\n";
 cout << rand()%10;
 for(int i=1; i<n; i++) cout << " " << 1+rand()%20;
 cout << "\n";
 return 0;
}

