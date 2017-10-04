#include<iostream>
using namespace std;
int main()
{
    int a,b,c,p;
    cin>>a>>b>>c;
    if(a<b+c && b<a+c && c<a+b)// ako ima triagalnik sas strani a, b i c
    {        
            //namirame obikolkata mu
             p=a+b+c;
             if(a==b&&a==c )   cout<<p<<" "<<1<<endl;          
                                
                              
                             
                             else
             
             {
                             if(a==b || a==c || b==c) cout<<p<<" "<<2<<endl;                                    
                                      
                             if(a!=b && a!=c && b!=c) cout<<p<<" "<<3<<endl;
                                      
                                      
              }
    }
             else cout<<"NO"<<endl;
             system("pause");
             return 0;
             }
