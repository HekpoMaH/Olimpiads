#include <iostream.h>
int main()
{
    int n,k,N[100][100],a,b,X,Y,max=0,angle[9999],c,d=1,e=1;
    cin >> n >> k;
    for(a=1;a<=n;a++)
    for(b=1;b<=n;b++)
    cin >> N[a][b];
    for(a=n+1;a<=100;a++)
    for(b=n+1;b<=100;b++)
    N[a][b]=0;         
    for(b=1;b<=n;b++)
    for(a=1;a<=n;a++)
    for(c=1;c<=n*n;c++)
    {
    do
    {
      angle[c]=N[a+d][b]+N[a][b+e];
      d++;
      e++;
      }
      while(d<=k);
      angle[c]=angle[c]+N[a][b];
      if(angle[c]>max) 
      {
       X=a;
       Y=b;
       }
      }
           
      cout<<X << " " << Y  << endl;
      return 0;
      
      }
      
      
      
      
      
      
    
    
