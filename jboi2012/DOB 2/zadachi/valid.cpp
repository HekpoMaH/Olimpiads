//valid
#include<iostream>
using namespace std;
int main()
{
    int d,m,g;
    cin>>d>>m>>g;
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 ||m==12)
            {          
                    if(d>31){
                              cout<<"No"<<endl;
                              cout<<"31"<<endl;
                              }
            
            
                              else
                              {
                              cout<<"Yes"<<endl;
                              if(d==31 && m!=12){cout<<"1."<<m+1<<".2008"<<endl;}
                              if(d==31 && m==12){cout<<"1.1.2009"<<endl;}
                              if(d<31){cout<<d+1<<"."<<m<<".2008"<<endl;}
                              }
                }
                if(m==4 || m==6 || m==9 || m==11)
                {
                        if(d>30)
                        {
                                cout<<"No"<<endl;
                                cout<<"30"<<endl;
                        }
                        else
                        {
                            cout<<"Yes"<<endl;
                            if(d==30){cout<<"1."<<m+1<<".2008"<<endl;}
                            if(d<31){cout<<d+1<<"."<<m<<".2008"<<endl;}
                        }
                }
                if(m==2)
                {
                        if(d>29)
                        {
                                cout<<"No"<<endl;
                                cout<<"29"<<endl;
                        }
                        else
                        {
                            cout<<"Yes"<<endl;
                            if(d==29){cout<<"1.3.2008"<<endl;}
                            if(d<29){cout<<d+1<<"."<<m<<".2008"<<endl;}
                        }
                }
                return 0;        
}
                
              
