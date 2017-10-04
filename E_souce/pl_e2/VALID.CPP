#include<iostream.h>
void main(){
int d,m,g;
cin>>d>>m>>g;
if((m==1 || m==3 ||m==5 || m==7||m==8||m==10) && d==31)
{cout<<"yes"<<(d-d)+1<<'.'<<m+1<<'.'<<g;return;}
else if((m==1||m==3||m==5||m==7||m==8||m==10) && d>31) {cout<<"no"<<31;return;}
if(d<31) {cout<<"yes"<<d+1<<'.'<<m<<'.'<<g;return;}
if(m==2 && d==29)
{cout<<"yes"<<(d-d)+1<<'.'<<m+1<<'.'<<g;return;}
else if (m==2 && d>29) {cout<<"no"<<29;return;}
if(m==2 && d<29) {cout<<"yes"<<d+1<<'.'<<m<<'.'<<g;return;}
if((m==4 || m== 6 || m==9 || m==11) && d==30)
{cout<<"yes"<<(d-d)+1<<'.'<<m+1<<'.'<<g<<endl;;return;}
else if((m==4 || m== 6 || m==9 || m==11) && d>30){cout<<"no"<<30;return;}
if((m==4 || m== 6 || m==9 || m==11) && d<30) {cout<<"yes"<<d+1<<'.'<<m<<'.'<<g;return;}
if(m==12 && d==31){cout<<"yes"<<(d-d)+1<<'.'<<(m-m)+1<<'.'<<g+1;return;}
else if(d>31){cout<<"no"<<31;return;}
if(m==12 && d<31) {cout<<"yes"<<d+1<<'.'<<m<<'.'<<g;return;}

}
