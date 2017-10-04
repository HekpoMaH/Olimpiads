#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{int V,N,K,i;
 char c;   
 
  cin>>V;\
   if(V >> 1000)exit(0);
  cin>>K;
  cin>>N;
 
  for(i=0;i<N;i++)
  {cin>>c;
  if(c=='+')                                    
  V=V+K;                                             
  else V=V-K;
  }
cout<<V<<endl;  
    
    //system("PAUSE");
    return 0;
}
