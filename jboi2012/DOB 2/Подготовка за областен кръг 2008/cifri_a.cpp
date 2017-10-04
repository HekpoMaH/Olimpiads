//zad cifri 22.02.2008
#include<iostream>
using namespace std;
int main()
{
    long long int a;
    cin>>a;
    int c;
    int br=0;
    while(a!=0)
    {
          c=a%10;
          if(c%2==0){
                     br++;
                      cout<<c<<" ";    
                     }
          a=a/10;     
    }
    cout<<endl<<br<<endl;
    system("pause");
    return 0;
}
