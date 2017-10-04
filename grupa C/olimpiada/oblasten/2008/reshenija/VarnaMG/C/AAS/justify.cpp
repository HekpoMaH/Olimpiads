#include <iostream>

using namespace std;

int main() {
  char  c[60];
  int n,i,j;
  cin>>n;
  for(i=0;i<=n;i++){
  gets(c);
  if(i==0)continue;
  int l=strlen(c),brd=0,bri=0,j;
  if(i==n)
  {
    int b=0;
    if(c[b]==' ')
    {
      while(c[b]==' ')
      {b++;}
      }
    for(j=b;j<l;j++)
    {
      if(c[j]!=' ') cout<<c[j];
      else 
      {
        while(c[j]==' ')
        {
          j++;
        }
       j--; 
       cout<<" ";
      } 
      
    }
    cout<<"\n";
    }
    else
    {
  
  if(c[0]==' ') bri++;
  for(j=1;j<l;j++)
  {
    if(c[j]==' ') 
    {
      bri++;
      if(c[j-1]!=' ')  brd++;
      }
  }
  bri+=60-l;
  int brm=0,ost=bri%brd,del=bri/brd,a,b=0;
  
  if(c[0]==' ')
  {
    while(c[b]==' ')
    {b++;}
  }
  for(j=b;j<l;j++)
  {
   if(c[j]!=' ') cout<<c[j];
   else 
   {
      brm++; while(c[j]==' ')
       {
          j++;
        }   
        j--;
      if(brm>ost){
      for(a=0;a<del;a++) {cout<<" ";}
      }
      else {
        for(a=0;a<=del;a++) {cout<<" ";}
        }
      
   }
    
  }
  cout<<"\n";
   }}
  return 0;
}
