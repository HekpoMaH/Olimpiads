#include <iostream>
using namespace std;
int nod(int a, int b)
 {
  while(a!=b)
   {
    if(a>b) a-=b;
    else b-=a;
   }
  return a;
 }
int nok(int a, int b)
 {
  int i, t;
  if(a<b)
    t=a;
  else t=b;
  while(t%a!=0 || t%b!=0) t++;
  return t;
 }
int main()
 {
  int n, i, ch[20], zn[20], dnok;
  cin>>n;
  for(i=0; i<n; i++) { cin>>ch[i]; cin>>zn[i]; }
  dnok=nok(zn[0], zn[1]);
  for(i=2; i<n; i++)
   dnok=nok(zn[i], dnok);
  for(i=0; i<n; i++)
   {
    ch[i]*=dnok/zn[i];
    zn[i]=dnok;
   }
  for(i=0; i<n-1; i++)
   for(int j=i+1; j<n; j++) if(ch[j]<ch[i]) { swap(ch[i], ch[j]); swap(zn[i], zn[j]); }
  for(i=0; i<n; i++)
   {
    int nd=nod(ch[i], zn[i]);
    ch[i]/=nd;
    zn[i]/=nd;
   }
  cout<<n<<endl;
  for(i=0; i<n; i++)
   cout<<ch[i]<<' '<<zn[i]<<'\n';
  return 0;
 }
