// Author: Plamenka Hristova
// Program: barrels
#include <iostream>
using namespace std;
 int  s,n,i,p,w,k=1000000000,j;
 int B[10000] ;
 void minbar(int p,int T, int m)
 {
  int br;
  br=(s-T)/B[p];
  if (m+br<k) {
   if (T+br*B[p]==s)k=m+br;
            else if (p<n) while (br>=0)
            {
            minbar(p+1, T+br*B[p],m+br);
            br--;
            }
   }
 }
 int main()
{
  cin >> s>>n;
  for(i=1;i<=n;i++) cin >>B[i];
  for (i=n; i>=2; i--){
       p=1;
       for (j=2; j<=i; j++)
               if (B[p]>B[j])p=j;
               w=B[p]; B[p]=B[i]; B[i]=w;
           }
  minbar(1,0,0);
  cout <<k<<endl;
}


