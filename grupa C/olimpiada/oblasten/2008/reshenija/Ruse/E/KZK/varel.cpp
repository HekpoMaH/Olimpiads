#include<iostream>
using namespace std;
int main ()
{
    int n,v,k,brm=0,brp=0,br=0;
    char p,m;
    cin>>v;
    cin>>k;
    cin>>n;
    cin.get (p);
    cin.get (m);
     do
    {
    if  (cin.get (m)) brm++;
    if (cin.get (p)) brp++;
    br=brm+brp;
    br=br-2;
if (brp>brm) v=v+k*(brp-brm)+10;
    else  v=v-k*(brm-brp);
}
                 while (br<=n);
    cout<<v<<endl;
    return 0;
}
      
    
     
