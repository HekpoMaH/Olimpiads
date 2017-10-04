#include<iostream>
using namespace std;
int main()
{
int pp,dd,mm,gggg=2008;
cin>>dd>>mm>>gggg;
pp=dd+1;
{
if((mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)&&(dd<31))  
cout<<"Yes"<<"\n";
cout<<pp<<" "<<mm<<" "<<gggg<<"\n";
return 0;
}
{
if((mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)&&(dd>31))
cout<<"No"<<"\n";
cout<<31<<"\n";
return 0;
}
{
if(mm==4||mm==6||mm==9||mm==11&&dd<30)  cout<<"Yes"<<"\n";
cout<<pp<<" "<<mm<<" "<<2008<<"\n";
return 0;
}
{
if(mm==4||mm==6||mm==9||mm==11&&dd>30)   cout<<"No"<<"\n";
cout<<30<<"\n";
return 0;
}
{
if(mm==2&&dd<29)  
cout<<"Yes"<<"\n"<<pp<<" "<<mm<<" "<<2008<<"\n";
return 0;
}
{
if(mm==2&&dd>29)    cout<<"No"<<"\n";
cout<<29<<"\n";
}
return 0;
}  

