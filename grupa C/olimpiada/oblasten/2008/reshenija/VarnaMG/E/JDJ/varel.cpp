#include<iostream>
using namespace std;
int main()
{
    int V,K,N,i,pl=0,min=0,br;
    char c;
    cin>>V>>K>>N;
    if(V<=1000 && K<=20 && N<=50)
    {
               for(i=0;i<N;i++)
    {
                    cin>>c;
                    if(c=='+') pl++;
                    if(c=='-') min++;
    }
    if(pl>min)
    {
               br=pl-min;
               cout<<V+K*br<<endl;
    }
    if(min>pl)
    {
              br=min-pl;
              cout<<V-K*min<<endl;
    }
    if(min==pl) cout<<V<<endl;
    return 0;
}
}
