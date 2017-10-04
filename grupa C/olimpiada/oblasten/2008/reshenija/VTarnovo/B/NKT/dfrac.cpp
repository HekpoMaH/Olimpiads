#include <iostream>

using namespace std;

int main()
{
    double a,b,k,p,e;
    long long int u=1,v=10,f;
    cin >> a >> b >> k >> p;
    
    for(int i=2;i<=k+p;i++)
    { 
            u=u*10;
            if(i<=p)v=v*10;
    }
    
    f=(a/b)*u;
    f=f%v;
    
    if(f==0)
      for(int i=1;i<=p;i++)
       cout << f;
    else 
       cout << f;
       
    cout << endl;
       

    cin >> e;
    return 0;
}
