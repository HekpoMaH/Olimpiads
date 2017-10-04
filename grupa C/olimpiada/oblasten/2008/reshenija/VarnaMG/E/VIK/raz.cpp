#include <iostream>
using namespace std;
int main ()
{
    int N,f,b,c,d,br,n,m,a;
    cin>>N;
    c=0;
        for (a=0;a<N;a++ && c++)
        {
            c++;
              if (N%c==0)
              {
                    b=N;
                    while (b=0)
                    {
                        b--; 
                            if (N%b==0)
                            {
                                if (c*b==N)
                                {
                                    cout<<c<<" "<<b;
                                }   
                            }
                      }
              }
        }
    
    
system ("pause");
return 0;
}
        
        
