#include<iostream>
using namespace std;
int main ()
{int dd,mm,gggg;
cin>>dd>>mm>>gggg;
if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)
if(dd<=31)
{cout<<"Yes"<<"\n";
if(dd+1>31)
cout<<1<<"."<<mm+1<<"."<<gggg;
else
cout<<dd+1<<"."<<mm<<"."<<gggg;
}
else 
{cout<<"No"<<"\n";
cout<<"31"<<"\n";
}
if(mm==4|| mm==6 || mm==9 ||mm==11)
if(dd<=30)
{cout<<"Yes"<<"\n";
if(dd+1>30)
cout<<1<<"."<<mm+1<<"."<<gggg;
else
cout<<dd+1<<"."<<mm<<"."<<gggg;
}
else
{cout<<"No"<<"\n";
cout<<"30"<<"\n";
}
if(mm==2)
{if(gggg%4==0 && gggg%100!=0 || gggg%400==0)
if(dd<=29)
{cout<<"Yes"<<"\n";
if(dd+1>29)
cout<<1<<"."<<mm+1<<"."<<gggg;
if(dd<29)
cout<<dd+1<<"."<<mm<<"."<<gggg;
}
else
cout<<"No"<<"\n"<<"29"<<"\n";
if(gggg%4!=0 &&  gggg%400!=0)
if(dd<=28)
{cout<<"Yes"<<"\n";
if(dd==28)
cout<<1<<"."<<mm+1<<"."<<gggg;
if(dd<28)
cout<<dd+1<<"."<<mm<<"."<<gggg;
}
else
cout<<"No"<<"\n"<<"28"<<"\n";
}
cout<<endl;
return 0;
}












