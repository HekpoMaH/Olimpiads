#include<iostream>
using namespace std;
int main()
{
    int a,b,x,y,brh,brv,sh,sv;
    cin>>a>>b>>x>>y;
    brh=(a/x)*(b/y);
    sh=a*b-brh*(x*y);
    brv=(a/y)*(b/x);
    sv=a*b-brv*(x*y);
    if(brh>brv)
    {
               cout<<brh<<endl<<sh<<endl;
               }
               else
               {
                   cout<<brv<<endl<<sv<<endl;
                   }
                  
                   return 0;
                   }
