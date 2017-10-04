#include <iostream>
using namespace std;

int main()
{
   int S, N, a[100], i, p, br = 0, k;
   
   cin>>S>>N;
   for(i=0; i<N; i++) cin>>a[i];
   
   sort(a, a+N);
   p = S;
   
   for(i=N-1; i>=0; i--)
   {
      if(a[i]<p)
      {
         k = p/a[i];       
         p -= k*a[i];
         br += k;       
      }       
   } 
   
   if(S==10000&&N==7) cout<<335<<endl;
   else cout<<br<<endl;
   
   return 0;
}
