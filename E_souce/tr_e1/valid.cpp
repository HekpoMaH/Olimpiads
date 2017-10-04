#include <iostream>
using namespace std;
int main ()
{
int d,m,g;
cin>>d>>m>>g;
if (m==1 && d<=30 && d>1) 
{
         cout<<"Yes"<<endl; 
         cout<<d+1<<"."<<m<<"."<<g<<endl;
         }
if (m==1 && d==31)
{
          cout<<"Yes"<<endl; 
          cout<<"1"<<"."<<m+1<<"."<<g<<endl;
          }
if (m==2 && d<=28 && d>1)
{
          cout<<"Yes"<<endl; 
          cout<<d+1<<"."<<m<<"."<<g<<endl;
          }
if (m==2 && d==29)
{
          cout<<"Yes"<<endl; 
          cout<<"1"<<"."<<m+1<<"."<<g<<endl;
          }
if (m==3 && d<=30 && d>1)
{
          cout<<"Yes"<<endl; 
          cout<<d+1<<"."<<m<<"."<<g<<endl;
          }
if (m==3 && d==31)
{
          cout<<"Yes"<<endl;
           cout<<"1"<<"."<<m+1<<"."<<g<<endl;
           }
if (m==4 && d<=29 && d>1)
{ 
          cout<<"Yes"<<endl; 
          cout<<d+1<<"."<<m<<"."<<g<<endl;
          }
if (m==4 && d==30)
{
          cout<<"Yes"<<endl; 
          cout<<"1"<<"."<<m+1<<"."<<g<<endl;
          }
if (m==5 && d<=30 && d>1)
{
          cout<<"Yes"<<endl;
           cout<<d+1<<"."<<m<<"."<<g<<endl;
           }
if (m==5 && d==31)
{
          cout<<"Yes"<<endl;
           cout<<"1"<<"."<<m+1<<"."<<g<<endl;
           }
if (m==6 && d<=29 && d>1)
{
          cout<<"Yes"<<endl;
           cout<<d+1<<"."<<m<<"."<<g<<endl;
           }
if (m==6 && d==30)
{
          cout<<"Yes"<<endl; 
          cout<<"1"<<"."<<m+1<<"."<<g<<endl;
          }
if (m==7 && d<=30 && d>1)
{
          cout<<"Yes"<<endl;
           cout<<d+1<<"."<<m<<"."<<g<<endl;
           }
if (m==7 && d==31)
{
          cout<<"Yes"<<endl;
           cout<<"1"<<"."<<m+1<<"."<<g<<endl;
           }
if (m==8 && d<=30 && d>1)
{
          cout<<"Yes"<<endl; 
          cout<<d+1<<"."<<m<<"."<<g<<endl;
          }
if (m==8 && d==31)
{
          cout<<"Yes"<<endl; 
          cout<<"1"<<"."<<m+1<<"."<<g<<endl;
          }
if (m==9 && d<=29 && d>1)
{
          cout<<"Yes"<<endl; 
          cout<<d+1<<"."<<m<<"."<<g<<endl;
          }
if (m==9 && d==30)
{
          cout<<"Yes"<<endl; 
          cout<<"1"<<"."<<m+1<<"."<<g<<endl;
          }
if (m==10 && d<=30 && d>1)
{
           cout<<"Yes"<<endl;
            cout<<d+1<<"."<<m<<"."<<g<<endl;
            }
if (m==10 && d==31)
{
           cout<<"Yes"<<endl;
            cout<<"1"<<"."<<m+1<<"."<<g<<endl;
            }
if (m==11 && d<=29)
{
           cout<<"Yes"<<endl; 
           cout<<d+1<<"."<<m<<"."<<g<<endl;
           }
if (m==11 && d==30)
{
           cout<<"Yes"<<endl;
            cout<<"1"<<"."<<m+1<<"."<<g<<endl;
            }
if (m==12 && d<=30 && d>1)
{
           cout<<"Yes"<<endl;
            cout<<d+1<<"."<<m<<"."<<g<<endl;
            }
if (m==12 && d==31)
{
           cout<<"Yes"<<endl;
            cout<<"1"<<"."<<"1"<<"."<<g+1<<endl;
            }
            if (m==1 && d>31) 
            {
                     cout<<"No"<<endl;
                     cout<<"31"<<endl;
                     }
                     if (m==2 && d>29) 
            {
                     cout<<"No"<<endl;
                     cout<<"29"<<endl;
                     }
                     if (m==3 && d>31) 
            {
                     cout<<"No"<<endl;
                     cout<<"31"<<endl;
                     }
                     if (m==4 && d>30) 
            {
                     cout<<"No"<<endl;
                     cout<<"30"<<endl;
                     }
                     if (m==5 && d>31) 
            {
                     cout<<"No"<<endl;
                     cout<<"31"<<endl;
                     }
                     if (m==6 && d>30) 
            {
                     cout<<"No"<<endl;
                     cout<<"30"<<endl;
                     }
                     if (m==7 && d>31) 
            {
                     cout<<"No"<<endl;
                     cout<<"31"<<endl;
                     }
                     if (m==8 && d>31) 
            {
                     cout<<"No"<<endl;
                     cout<<"31"<<endl;
                     }
                     if (m==9 && d>30) 
            {
                     cout<<"No"<<endl;
                     cout<<"30"<<endl;
                     }
                     if (m==10 && d>31) 
            {
                     cout<<"No"<<endl;
                     cout<<"31"<<endl;
                     }
                     if (m==11 && d>30) 
            {
                     cout<<"No"<<endl;
                     cout<<"30"<<endl;
                     }
                     if (m==12 && d>31) 
            {
                     cout<<"No"<<endl;
                     cout<<"31"<<endl;
                     }
                     if (m==1 && d==0)
                     {
                              cout<<"No"<<endl;
                     cout<<"31"<<endl;
                     }
                      if (m==3 && d==0) 
                      {
                               cout<<"No"<<endl;
                               cout<<"31"<<endl;
                               }
                               if (m==5 && d==0)
                               {
                                        cout<<"No"<<endl;
                                        cout<<"31"<<endl;
                                        }
                                        if (m==7 && d==0)
                                        {
                                                 cout<<"No"<<endl;
                                                 cout<<"31"<<endl;
                                                 }
                                                 if ( m==8 && d==0)
                                                 {
                                                      cout<<"No"<<endl;
                                                      cout<<"31"<<endl;
                                                      }
                                                 if (m==10 && d==0)
                                                 {
                                                           cout<<"No"<<endl;
                                                           cout<<"31"<<endl;
                                                           }
                                                 if (m==12 && d==0)
                                                 {
                                                           cout<<"No"<<endl;
                                                           cout<<"31"<<endl;
                                                           }
                     if (m==4 && d==0)
                     {
                              cout<<"No"<<endl;
                     cout<<"30"<<endl;
                     }
                     if (m==6 && d==0)
                     {
                              cout<<"No"<<endl;
                              cout<<"30"<<endl;
                              }
                              if (m==9 && d==0)
                              {
                                       cout<<"No"<<endl;
                                       cout<<"30"<<endl;
                                       }
                                       if (m==11 && d==0)
                                       {
                                                 cout<<"No"<<endl;
                                                 cout<<"30"<<endl;
                                                 }
                     if (m==2 && d==0)
                     {
                     cout<<"No"<<endl;
                     cout<<"29"<<endl;
                     }
 return 0;   
}
