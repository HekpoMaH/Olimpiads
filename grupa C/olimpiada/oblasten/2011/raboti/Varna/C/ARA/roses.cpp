#include <iostream>
using namespace std;

int main()
{
   int M, N, K, i, j, k, l, sb = 0, tempSb, max = 0, sbCols = 0, col=0;
   int a[500][500];
   
   cin>>M>>N>>K;
   
   for(i=0; i<M; i++)
      for(j=0; j<N; j++)
      {
         cin>>k;
         sb += k;
         a[i][j] = k;
      }
   
   for(i=0; i<M-K+1; i++)
   {
      tempSb = 0;      
      for(k=0; k<K; k++)
      {    
         for(l=0; l<K; l++)
         {  
            tempSb += a[i+k][l];      
         }     
      }      
            
      for(j=0; j<N-K+1; j++)
      {     
         for(k=0; k<K; k++) tempSb -= a[i+k][j];  
         for(k=0; k<K; k++) tempSb += a[i+k][j+K];  
         if(tempSb>max) max = tempSb;      
      }      
   }
   
   k = sb-max;
   
   cout<<k<<endl;
   
   return 0;
}
