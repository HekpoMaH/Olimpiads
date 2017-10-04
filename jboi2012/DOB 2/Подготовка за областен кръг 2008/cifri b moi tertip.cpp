//zad cifri 22.02.2008
#include<iostream>
using namespace std;
int main()
{
    long long int a;
    cin>>a;
    int c;
    int suma=0;
    while(a!=0)
    {
          c=a%10;
          if(c%2==1){
                    suma=suma+c;
                      cout<<c<<" ";    
                     }
          a=a/10;     
    }
    cout<<endl<<s<<endl;
    system("pause");
    return 0;
} 
               
