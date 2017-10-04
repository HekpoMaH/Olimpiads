//fib10
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long int a,c,b;
    a=1;
    b=1;
    int num=3;
    if(n==1 || n==2){cout<<1<<endl;}
    else
    {
    while (num<=n)
    {
          c=a+b;
          a=b;
          b=c;
          num++;  
    }
    cout<<c<<endl;
      }
    
    system("pause");
    return 0;
}
