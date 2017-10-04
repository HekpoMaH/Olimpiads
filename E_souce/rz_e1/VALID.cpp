#include <iostream>
using namespace std;

  
 int main()
  {
      int d=0,m=0,g=0;
      int vd=0,vm=0;
      cin>>d>>m>>g;
      if (d != 0 && m != 0 && m != 2)
      {    
           if (d < 31 && d >=1)
           {
              vd=d+1;
              vm=m;
              if (vd > 31 ) 
              {
                 vd =1;
                 vm= m+1;   
              }
           }
             cout<<"Yes"<<endl;
             cout<<vd<<"."<<vm<<"."<<"2008"<<endl;          
          
      }else
      {
          if (m == 1 ) 
          {
                       cout<<"No"<<endl;
                       cout<<"31"<<endl;
          }
          if (m == 2 )
          {
                        cout<<"No"<<endl;
                        cout<<"29"<<endl;
          } 
            if (m == 3 )
          { 
                 cout<<"No"<<endl;
                 cout<<"30"<<endl;
          }
          if (m == 4 ) 
          {
                       cout<<"No"<<endl;
                       cout<<"31"<<endl;
          }
          if (m == 5 )
          { 
                 cout<<"No"<<endl;
                 cout<<"30"<<endl;
          }
          if (m == 6 ) 
          {
                       cout<<"No"<<endl;
                       cout<<"31"<<endl;
          }
            if (m == 7 )
          { 
                 cout<<"No"<<endl;
                 cout<<"30"<<endl;
          }
           if (m == 8 ) 
          {
                       cout<<"No"<<endl;
                       cout<<"31"<<endl;
          }
            if (m == 9 )
          { 
                 cout<<"No"<<endl;
                 cout<<"30"<<endl;
          }
           if (m == 10 ) 
          {
                       cout<<"No"<<endl;
                       cout<<"31"<<endl;
          }
           if (m == 11 )
          { 
                 cout<<"No"<<endl;
                 cout<<"30"<<endl;
          }
          if (m == 12 ) 
          {
                       cout<<"No"<<endl;
                       cout<<"31"<<endl;
          }
      }
      system ("PAUSE");
      return 0;
 } 
