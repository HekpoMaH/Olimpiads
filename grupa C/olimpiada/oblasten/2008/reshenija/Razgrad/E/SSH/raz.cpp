#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
     int N,;
     int raz=100,ch1,ch2;//raz e razlikat mejdu ch1 i ch2
     cin>>N;  
     for(int i=1;i<=N;i++)
     {
             for(int j=1;j<=N;j++)
             {
                     if (j*i == N)
                     {
                           if (j >= i)
                           {
                                if (raz > j-i)
                                {
                                    raz=j-i;
                                    ch1=i;
                                    ch2=j;
                                } 
                           }else
                           {
                                if(raz > i-j)
                                {
                                     raz=i-j;
                                     ch1=j;
                                     ch2=i;  
                                }                               
                           }  
                     }else
                     {
                          continue;
                     }
             }
     }
     cout<<ch1<<" "<<ch2<<endl;    
     //system ("PAUSE");    
     return 0;    
}
