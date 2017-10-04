#include <iostream>
using namespace std;
int main (){
int dd,mm,gggg;
cin>>dd>>mm;
gggg=2008;
  if (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 && dd==31) cout<<"Yes"<<endl<<"1"<<"."<<mm+1<<"."<<gggg<<endl;;
  if (mm==4 || mm==6 || mm==9 || mm==11 && dd==30) dd=0;mm+1;
  if (mm==2 && dd==29) dd==0;mm+1;
  if (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 && 31>dd) cout<<"Yes"<<endl<<dd+1<<"."<<mm<<"."<<gggg<<endl;
  if (mm==4 || mm==6 || mm==9 || mm==11 && 30>dd) cout<<"Yes"<<endl<<dd+1<<"."<<mm<<"."<<gggg<<endl;
  if (mm==2 && 29>dd)  cout<<"Yes"<<endl<<dd+1<<"."<<mm<<"."<<gggg<<endl;
  if (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 && dd>31) cout<<"No"<<endl<<"31"<<endl;
  if (mm==4 || mm==6 || mm==9 || mm==11 && dd>30) cout<<"No"<<endl<<"30"<<endl;
  if (mm==2 && dd==29)cout<<"No"<<endl<<"29"<<endl;
  //system ("pause");
return 0;
}
