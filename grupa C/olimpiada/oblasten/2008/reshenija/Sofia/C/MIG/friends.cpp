#include <iostream.h>
using namespace std;
int main()
{
    int N,M,x,y,p=1,br1=1,br[2000],last[2000],max=0,a,b,c;
    cin >> N >> M;
    for(b=1;b<=N;b++)
    {
    last[b]=0;
    }
    for(c=1;c<=N;c++)
    {
    br[c]=1;
    }
    do
    {
      cin >> x >> y;          
      for(a=1;a<=N;a++)
      if(x==last[a]) br[x]++;
      if(br1==br[x]) 
      {
      last[x]=x;
      if(br[x]>max) max=br[x];
      }
      br1=br[x];
      p++;
      }
      while(p<=M);
      if(br[x]>max) max=br[x];
      cout << max <<endl;
      return 0;
      }
      
      
      
    
    
    
