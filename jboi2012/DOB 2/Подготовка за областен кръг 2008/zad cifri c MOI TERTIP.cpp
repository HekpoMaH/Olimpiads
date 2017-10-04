//zad cifri c MOI TERTIP
#include<iostream>
using namespace std;
int main()
{
    long long int a;
    cin>>a;
    int c;
    int chislo1=0;
    int chislo2=0;
    while(a!=0)
    {
          c=a%10;
          if(c%2==0){
                     chislo1=chislo1*10+c;  
                     }
          a=a/10;     
    }
    while (chislo1!=0)
    {
          c=chislo1%10;
          chislo2=chislo2*10+c;
          chislo1=chislo1/10;
    }       
    cout<<chislo2<<endl;
    return 0;
}
