// пролетен турнир 2007
//color
#include<iostream>
using namespace std;



int main()
{
    int l, n;
    int r[5], b[5], w[5];
    int p[10001];

  cin >> l >> n;
  for(int i=1;i<=n;i++) 
          {
                        cin >> r[i] >> b[i] >> w[i];
          }            

  for(int i=1;i<=n;i++)
  {  
   int j=1;
   while(j<l)
   {
    for(int k=1;k<=r[i];k++) {if(j>=l) break; p[j]=1; j++;}            
    for(int k=1;k<=b[i];k++) {if(j>=l) break; p[j]=2; j++;}    
    for(int k=1;k<=w[i];k++) {if(j>=l) break; j++;}        
   } 
  } 

  int br=0;
  for(int i=1;i<=l;i++)
  if(p[i]==1) br++;
  
  cout << br << endl;
  system ("pause");
  return 0;

}
