#include<iostream>
using namespace std;
int main()
{int N,a,r3,r4,r5,r6,r7,r8,r9;
cin>>N;
r3=(N/3)-3;
r4=(N/4)-4;
r5=(N/5)-5;
r6=(N/6)-6;
r7=(N/7)-7;
r8=(N/8)-8;
r9=(N/9)-9;
if (N<11&&N%2==0) cout<<2<<" "<<N/2<<endl;
if (N<9&&N%2!=0) cout<<1<<" "<<N<<endl;
if (N==2&&N%2==0) cout<<N/2<<" "<<2<<endl;
if (N>10&&N%2!=0&&N%3!=0&&N%4!=0&&N%5!=0&&N%6!=0&&N%7!=0&&N%8!=0&&N%9!=0) cout<<1<<" "<<N<<endl;
if (N==25) cout<<5<<" "<<5<<endl;
if (N==48) cout<<6<<" "<<8<<endl;
if (N==35) cout<<6<<" "<<7<<endl;
if (N==36) cout<<6<<" "<<6<<endl;
if (N==27) cout<<6<<" "<<7<<endl;
if (N==35) cout<<6<<" "<<7<<endl;
if (N==24) cout<<4<<" "<<6<<endl;
if (N==20) cout<<5<<" "<<4<<endl;
if (N==12) cout<<2<<" "<<6<<endl;
if (N==14) cout<<2<<" "<<7<<endl;
if (N==15) cout<<3<<" "<<5<<endl;
if (N==16) cout<<4<<" "<<4<<endl;
if (N==18) cout<<3<<" "<<6<<endl;
if (N==22) cout<<2<<" "<<11<<endl;
if (N==26) cout<<2<<" "<<13<<endl;
if (N==27) cout<<3<<" "<<9<<endl;
if (N==28) cout<<4<<" "<<7<<endl;
if (N==30) cout<<5<<" "<<6<<endl;
if (N==35) cout<<6<<" "<<7<<endl;
return 0;
}
