#include <iostream>
 using namespace std;

int main ()
{
    int n,ch=0,fib=0;
    cin>>n;
    if (n >= 1 && n <= 1000)
    {
         for (int i=0;i<=n;i++)
         {
              ch=ch+(ch+1);                     
         }
         
    }
    cout<<ch<<endl;
    
    
    system ("PAUSE");
    return 0;
}
