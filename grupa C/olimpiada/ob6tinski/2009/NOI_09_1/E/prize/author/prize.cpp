//prize
#include<iostream>
using namespace std;
int main()
{

    int oc,br1=0,br2=0;
    for(int i=1;i<=7;i++)
    {
       cin>>oc;
       if(oc==2){br1++;}
       if(oc==6){br2++;}
    } 
    if(br1!=0 || br2==0)cout<<"No"<<endl; 
    else {         
          for(int i=1;i<=br2;i++) cout<<"*";
          cout<<endl;    
         }
   return 0;
}        
    
