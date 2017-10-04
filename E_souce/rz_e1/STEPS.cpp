#include <iostream>
 using namespace std;

  int main()
  {
      int N,H,L;
      char S;
      cin>>N>>H>>L;
      cin.get(S);
      if (N > 0 && N <= 10 && H > 1 && H <= 7 && L > 0 && L < 7 )
      {
         for (int i=0;i <= N;i++)
         {
               for (int j=0;j<=N+N;i++)
               {
                     cout<<S;  
               }                               
         }
      }          
      system ("PAUSE");
      return 0;
  } 
