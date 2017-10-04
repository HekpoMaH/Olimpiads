//lilies
#include<iostream>
using namespace std;
int main()
{
    int n,a1,a2,a3;
    cin>>n;
    if(n==1) {
             cin>>a1;
             cout<<1<<endl;
             }
    if(n==2) {
             cin>>a1>>a2;
             if(a1>a2) {cout<<a1+1<<endl;} 
             else {cout<<a2+1<<endl;}
             }       
    
    if (n==3) 
              {cin>>a1>>a2>>a3;
              if(a1>a2&&a1>a3)
                              if(a2>a3) {cout<<a1+a2+1<<endl;}
                              else {cout<<a1+a3+1<<endl;}
              if(a2>a1&&a2>a3)
                              if(a1>a3) {cout<<a1+a2+1<<endl;}
                              else {cout<<a2+a3+1<<endl;}
              if(a3>a1&&a3>a1)
                              if(a1>a2) {cout<<a3+a1+1<<endl;}
                              else {cout<<a3+a2+1<<endl;}
             }                               
    return 0;
}                                                
