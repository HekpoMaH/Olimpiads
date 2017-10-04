#include<iostream>
#include<string>
using namespace std;
string barc;
int cnt,f1,s1,n,br;
unsigned long long s;
int main()
{
  cin>>barc;
  n=barc.size();
  for(int i=0;i<n;i++)
  {
    if(barc[i]-'0'==1){br++;}
    if(br%2==0){cout<<s<<endl;s=s*10+cnt-1;cout<<"2"<<s<<endl;cnt=0;}
    if(br%2==1)cnt++;
    cout<<cnt<<" "<<barc[i]<<endl;
    if((i==0&&barc[i]-'0'==0)||(i>0&&i<n-1&&barc[i-1]-'0'==0&&barc[i]==1&&barc[i+1]-'0'==0)){cout<<"Invalid barcode"<<endl;return 0;}
  }
  if(s>=0&&s<=13){cout<<"US"<<endl;return 0;}
  if(s>=30&&s<=37){cout<<"FR"<<endl;return 0;}
  if(s==380){cout<<"BG"<<endl;return 0;}
  if(s==383){cout<<"SL"<<endl;return 0;}
  if(s>=400&&s<=440){cout<<"D"<<endl;return 0;}
  if(s>=45&&s<=49){cout<<"JP"<<endl;return 0;}
  if(s>=460&&s<=469){cout<<"RU"<<endl;return 0;}
  if(s==471){cout<<"TW"<<endl;return 0;}
  if(s==50){cout<<"GB"<<endl;return 0;}
  if(s==520){cout<<"GR"<<endl;return 0;}
  if(s>=690&&s<=692){cout<<"CH"<<endl;return 0;}
  if(s>=80&&s<=83){cout<<"IT"<<endl;return 0;}
  if(s==84){cout<<"SP"<<endl;return 0;}
  cout<<s<<endl;
  return 0;
}
