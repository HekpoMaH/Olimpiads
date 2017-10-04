#include<iostream>
using namespace std;
long long k,p,la,lb,i,del=0,dmu=0,f,z;
char a[9],b[9];
int c[9],d[9];
int main()
{
    for(i=0; i<9; i++)
    {c[i]=0; b[i]=0; a[i]='0'; b[i]='0';}
    
    cin>>a;
    cin>>b;
    cin>>k>>p;
    
    int e[k+p];
    for(i=0; i<(k+p); i++)
    e[i]=0;
    
    la=strlen(a);
    lb=strlen(b);
    
    for(i=0; i<la; i++)
    c[i]=a[i]-'0';          
    for(i=0; i<lb; i++)
    d[i]=b[i]-'0';
    
    for(i=0; i<lb; i++)     
    del=del*10+d[i];
    
    i=0; dmu=0;
    for(f=0; f<(p+k); f++)
    {
                    if((i<la)&&(dmu<del))
                    {
                            for(i; i<la; i++)
                            {
                                   dmu=dmu*10+c[i];
                                   if(dmu>=del) 
                                   {i++; break;}
                             }
                     }
                    if(i==la) {z=f; i++;}
                    if((f>0)&&(i>=la)&&(dmu<del)) dmu=dmu*10;
                    if(dmu<del){do{dmu=dmu*10; e[f]=0; f++;}while(dmu<del);}
                    e[f]=dmu/del;
                    dmu=dmu-(del*e[f]);
     }
     
    for(i=k; i<(p+k); i++)
    {
             if(i==z) {cout<<e[i]<<",";}
             else cout<<e[i];
     }
    cout<<endl;
    return 0;}
