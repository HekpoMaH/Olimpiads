#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()

{
    long long a,b;
    float Del,jo;
    Del=a/b;
    int p;
    long long  k,l,S;
    cin>>a>>b;
    cin>>k>>p;
    l=k+55;
    int c[k];
    
 
    
    long long i=0;
    long long mn=1,ch;
    S=int(Del);
    for(int j=1;j<19;j++)
    mn=mn*10;
        
    if(S=0)
    {jo=Del;}
    else
    {
    jo=Del-S;
    }
    Del=jo;
    
    ch=long(jo*mn);
    for(long long i=0;i<l;i++)
    {
    c[i]=ch%10;
    ch=ch/10;
}
for(int i=p;i<k;i++)
{cout<<c[i];}

    
                 
           
    
    
    
return 0;
}
