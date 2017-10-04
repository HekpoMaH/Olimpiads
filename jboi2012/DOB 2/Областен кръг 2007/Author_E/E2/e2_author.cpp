#include<iostream>
using namespace std;
int main()
{
     long int p=1; long int a,s=0,br=0;
     while (p<1000) {
           cin >>a; br++;
           s+=a;
           if ((a>0)&&(a%2==0)) p*=a; 
           }
     cout <<s<<" "<<br<<endl;
     return 0;
}          
