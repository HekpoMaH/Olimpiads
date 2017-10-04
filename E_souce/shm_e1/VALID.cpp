#include<iostream>
using namespace std;
int main()
{
    int d,m,g;
    cin>>d>>m>>g;
        if(g==2008&&m==1&&d<=31)cout<<"Yes"<<endl<<d+1<<'.'<<m<<'.'<<g<<endl;
        if(g==2008&&m==1&&d==31)cout<<"Yes"<<endl<<"1"<<'.'<<m+1<<'.'<<g<<endl;
        if(g==2008&&m==2&&d<=29)cout<<"Yes"<<endl<<d+1<<'.'<<m<<'.'<<g<<endl;
        if(g==2008&&m==2&&d==29)cout<<"Yes"<<endl<<"1"<<'.'<<m+1<<'.'<<g<<endl;
        if(g==2008&&m==3&&d<=30)cout<<"Yes"<<endl<<d+1<<'.'<<m<<'.'<<g<<endl;
        if(g==2008&&m==3&&d==30)cout<<"Yes"<<endl<<"1"<<'.'<<m+1<<'.'<<g<<endl;
        if(g==2008&&m==4&&d<=31)cout<<"Yes"<<endl<<d+1<<'.'<<m<<'.'<<g<<endl;
        if(g==2008&&m==4&&d==31)cout<<"Yes"<<endl<<"1"<<'.'<<m+1<<'.'<<g<<endl;
        if(g==2008&&m==5&&d<=30)cout<<"Yes"<<endl<<d+1<<'.'<<m<<'.'<<g<<endl;
        if(g==2008&&m==5&&d==30)cout<<"Yes"<<endl<<"1"<<'.'<<m+1<<'.'<<g<<endl;
        if(g==2008&&m==6&&d<=31)cout<<"Yes"<<endl<<d+1<<'.'<<m<<'.'<<g<<endl;
        if(g==2008&&m==6&&d==31)cout<<"Yes"<<endl<<"1"<<'.'<<m+1<<'.'<<g<<endl;
        if(g==2008&&m==7&&d<=30)cout<<"Yes"<<endl<<d+1<<'.'<<m<<'.'<<g<<endl;
        if(g==2008&&m==7&&d==30)cout<<"Yes"<<endl<<"1"<<'.'<<m+1<<'.'<<g<<endl;
        if(g==2008&&m==8&&d<=31)cout<<"Yes"<<endl<<d+1<<'.'<<m<<'.'<<g<<endl;
        if(g==2008&&m==8&&d==31)cout<<"Yes"<<endl<<"1"<<'.'<<m+1<<'.'<<g<<endl;
        if(g==2008&&m==9&&d<=30)cout<<"Yes"<<endl<<d+1<<'.'<<m<<'.'<<g<<endl;
        if(g==2008&&m==9&&d==30)cout<<"Yes"<<endl<<"1"<<'.'<<m+1<<'.'<<g<<endl;
        if(g==2008&&m==10&&d<=31)cout<<"Yes"<<endl<<d+1<<'.'<<m<<'.'<<g<<endl;
        if(g==2008&&m==10&&d==31)cout<<"Yes"<<endl<<"1"<<'.'<<m+1<<'.'<<g<<endl;
        if(g==2008&&m==11&&d<=30)cout<<"Yes"<<endl<<d+1<<'.'<<m<<'.'<<g<<endl;
        if(g==2008&&m==11&&d==30)cout<<"Yes"<<endl<<"1"<<'.'<<m+1<<'.'<<g<<endl;
        if(g==2008&&m==12&&d<=31)cout<<"Yes"<<endl<<d+1<<'.'<<m<<'.'<<g<<endl;
        if(g==2008&&m==12&&d==31)cout<<"Yes"<<endl<<"1"<<'.'<<m+1<<'.'<<g<<endl;
        else
        if(m==1)cout<<"No"<<endl<<"31"<<endl;
        if(m==2)cout<<"No"<<endl<<"29"<<endl;
        if(m==3)cout<<"No"<<endl<<"30"<<endl;
        if(m==4)cout<<"No"<<endl<<"31"<<endl;
        if(m==5)cout<<"No"<<endl<<"30"<<endl;
        if(m==6)cout<<"No"<<endl<<"31"<<endl;
        if(m==7)cout<<"No"<<endl<<"30"<<endl;
        if(m==8)cout<<"No"<<endl<<"31"<<endl;
        if(m==9)cout<<"No"<<endl<<"30"<<endl;
        if(m==10)cout<<"No"<<endl<<"31"<<endl;
        if(m==11)cout<<"No"<<endl<<"30"<<endl;
        if(m==12)cout<<"No"<<endl<<"31"<<endl;
    
    return 0;
}
