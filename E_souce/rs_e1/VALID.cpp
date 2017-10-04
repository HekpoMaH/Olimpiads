#include<iostream>
using namespace std;
int main ()
{
    int d,m,g;
    cin>>d>>m>>g;
    if ((m==1 || m==3 || m==5 || m==7 || m==8 || m==10) && d<=31)
    {
             if (d==31) {m=m+1;d=1;}
             else d=d+1;
    }
    cout<<"Yes"; cout<<endl; cout<<d<<"."<<m<<"."<<"2008"<<endl;
    else cout<<"No"<<endl; cout<<"31"<<endl;
    
        if ((m==4 || m==6 || m==9 || m==11) && d<=30)
        {
                  if (d==30) {m=m+1;d=1;}
                  else d=d+1;
        }
    cout<<"Yes"<<endl; cout<<d<<"."<<m<<"."<<"2008"<<endl;
        else cout<<"No"<<endl; cout<<"30"<<endl;
    if (m==2 && d<=29)
    {
             if (d==29) {m=m+1; d=1;}
             else d=d+1;
    } 
    cout<<"Yes"<<endl; cout<<d<<"."<<m<<"."<<"2008"<<endl;
        else cout<<"No"<<endl; cout<<"29"<<endl;
    if (m==12 && d<=31)
    {
              if (d==31) {d=1;m=1;g=g+1;}
              else d=d+1;
    }  
    cout<<"Yes"<<endl; cout<<d<<"."<<m<<"."<<g<<endl;
    else cout<<"No"<<endl; cout<<"31"<<endl;
    system("pause");
    return 0;
}    
