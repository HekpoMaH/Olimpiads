#include<iostream>
using namespace std;

int L, N;
int r[5], b[5], w[5];
int p[10001];

int main()
{
  cin >> L >> N;
  for(int i=1;i<=N;i++) cin >> r[i] >> b[i] >> w[i];

  for(int i=1;i<=N;i++)
  {  
   int j=1;
   while(j<L)
   {
    for(int k=1;k<=r[i];k++) {if(j>=L) break; p[j]=1; j++;}            
    for(int k=1;k<=b[i];k++) {if(j>=L) break; p[j]=2; j++;}    
    for(int k=1;k<=w[i];k++) {if(j>=L) break; j++;}        
   } 
  } 

  int b=0;
  for(int i=1;i<=L;i++)
   if(p[i]==1) b++;
  
  cout << b << endl;

}
