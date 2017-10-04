#include <iostream>

using namespace std;

int main()
{
    int S,N,a[100],br[100],p,h=0,min,e;
    cin >> S >> N;
    
    for(int i=0;i<=N-1;i++)
      cin >> a[i];
    
    for(int i=N-1;i>=1;i--)
      for(int j=0;j<=i-1;j++)
       if(a[j]>=a[j+1])swap(a[j], a[j+1]);
       
    p=S;
    for(int i=0;i<=N-1;i++)
    {
              h=i;
              br[i]=0;
              p=S;
              while(p>0 && h<=N-1)
              {
                      while(a[N-1-h]<=p && p>0){
                                       br[i]=br[i]+1;
                                       p=p-a[N-1-h];
                                       }
                      h++;
              }          
    }
    
    min=br[0];
    for(int i=1;i<=N-1;i++)
     if(min>=br[i])min=br[i];
     
    cout << min << endl;

    cin >> e;
    return 0;
}
