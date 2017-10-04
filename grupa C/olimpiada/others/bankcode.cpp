#include<iostream>
#include<string>
using namespace std;
int num;
string code;
int main()
{
  cin>>num;
  if(num<10)
  {
    if(num==1){cout<<0<<endl;return 0;}
    code+="10";
    for(int i=2;i<num;i++)code+=(char)(i+'0');
    cout<<code<<endl;
    return 0;
  }
  if(num>=10&&num<=19)
  {
    code+=(char)(num%10+'0');
    code+="1";
    for(int i=0;i<=9;i++)if(i!=num%10&&i!=1)code+=(char)(i+'0');
    cout<<code<<endl;
    return 0;
  }
  if(num>19&&num<100)
  {
    int pc,used[12];
    pc=num/10;
    for(int i=1;i<pc;i++)code+=(char)(i+'0');
    for(int i=num%10;i<=pc;i++){used[i]=1;code+=(char)(i+'0');}
    if(num%10>pc){code+=(char)(num%10+'0');code+=(char)(pc+'0');used[pc]=1;used[num%10]=1;}
    for(int i=0;i<=9;i++)if(used[i]!=1){code+=(char)(i+'0');}
    cout<<code<<endl;
  }
  if(num>=100)
  {
    int pc,vc,tc,used[12];
    tc=num%10;
    num/=10;
    vc=num%10;
    num/=10;
    pc=num;
    for(int i=0;i<=11;i++)used[i]=0;
    for(int i=1;i<pc;i++)code+=(char)(i+'0');
    for(int i=vc;i<=pc;i++){used[i]++;code+=(char)(i+'0');}
    if(vc>pc){code+=(char)(vc+'0');code+=(char)(pc+'0');used[pc]++;used[vc]++;}
    for(int i=0;i<=9;i++)if(used[i]!=1){code+=(char)(i+'0');}
    for(int i=0;i<=11;i++)used[i]=0;
    for(int i=tc;i<=vc;i++){used[i]++;code+=(char)(i+'0');}
    if(tc>vc){code+=(char)(tc+'0');code+=(char)(vc+'0');used[tc]++;used[vc]++;}
    for(int i=0;i<=9;i++)if(used[i]!=1){code+=(char)(i+'0');}
    cout<<code<<endl;
  }
  return 0;
}
