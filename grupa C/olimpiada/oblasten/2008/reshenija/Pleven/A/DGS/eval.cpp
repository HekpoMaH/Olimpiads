#include <iostream>
#include <vector>
#include <string>
using namespace std;
string Str,Last;


int Fact(int Num){int Res=1;for(int i=1;i<Num+1;i++){Res*=i;};return Res;}

int main(){
cin>>Str;
int Res = 0;
for(int i=0;i<Str.size();i++){if((Str[i]=='*')||(Str[i]=='/')||(Str[i]=='^'))Res++;}
int LastNum=0;
for(int i=0;i<Str.size();i++){if(Str[i]=='^')LastNum++;}

Res=Fact(Res+1);

if(Res==0)Res++;
LastNum=1;
for(int i=0;i<Str.size();i++){
if((Str[i]=='+')&&(Last=="+"))LastNum++;
else if(Str[i]=='+'){Last="+";LastNum++;}
else if((Str[i]=='*')||(Str[i]=='/')||(Str[i]=='^')){Res=Res*Fact(LastNum-1);LastNum=1;}
}
Res=Res*Fact(LastNum);


cout<<Res<<"\n";

system("pause");
return 0;}
