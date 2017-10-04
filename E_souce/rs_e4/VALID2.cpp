#include<iostream>
using namespace std;
int main()
{
    int d,m,g,p;
    cin>>d>>m>>g;
       if(m==12)
    {
    p=31;
    if(d==p) {d=1;m=1;g++ ;cout<<"Yes"<<endl;cout<<d<<"."<<m<<"."<<g<<endl;}
    else {if(d>p) {cout<<"No"<<endl;cout<<p<<endl;}
          else {d=d+1;m=m;g=g; cout<<"Yes"<<endl;cout<<d<<"."<<m<<"."<<g<<endl;}}
          }; system("pause");
    if(m==2) 
    {
    p=29 ;      
    if(d>p){cout<<"No"<<endl;cout<<p<<endl;} 
    else {if(d==p) {d=1;m=m+1;cout<<"Yes"<<endl;cout<<d<<"."<<m<<"."<<g<<endl;} 
          else{d=d+1; cout<<"Yes"<<endl;cout<<d<<"."<<m<<"."<<g<<endl;} }
             
    };
    system("pause");
         if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) 
        {
        p=31;
                if(d>p) {cout<<"No"<<endl;cout<<p<<endl;}
                else {if(d==p) {d=1;m=m+1; cout<<"Yes"<<endl;cout<<d<<"."<<m<<"."<<g<<endl;}
                      else {d=d+1; cout<<"Yes"<<endl;cout<<d<<"."<<m<<"."<<g<<endl;}}
                
        }; 
        system ("pause");
         if(m=4 || m==6 || m==9 || m==11) p=30;
        {
             if(d==p) {d=1;m=m+1; cout<<"Yes"<<endl;cout<<d<<"."<<m<<"."<<g<<endl;}
             else {if(d>p) {cout<<"No"<<endl;cout<<p<<endl;}
             else {d=d+1; cout<<"Yes"<<endl;cout<<d<<"."<<m<<"."<<g<<endl;}}
    }; system("pause");
 
          return 0;
}  
        
    
            
