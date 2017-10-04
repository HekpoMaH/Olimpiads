#include <iostream>
using namespace std;
//unsigned long long long int N = 1000000000000000000; 
int main()
{
unsigned long long  int a, b, k,p, z, i;
// a=1; b=7;   k=7; p=230;
    cin>>a>>b>>k>>p;

/*double z; char x[1000];    z=a/b;    sprintf (x, "%.222f",z);     
for(int i =0; i<p; i++)   {   cout<<x[k+1]; k++; }  */
z= a %b;
unsigned long long int res[100000];
for(i=0; i<10000; i++)
{
   res[i]=0;
   res[i]= z/b; 
   if (res[i] == 0) {z = z*10; res[i]= z/b; }
   z = z%b; 
   //cout<<res[i];
}

for (i=0; i<p; i++)
{   cout<<res[k-1]; k++; }
cout <<endl;

    return 0;
}
