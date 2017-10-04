#include <iostream>
#include <stdlib.h>
using namespace std;
char exp[32];
struct exprs{
  char izr[32];
  char nizrz[32];
  int  pl;
}s[32];
int excount=1;
void makenewexpr(int st,int en){
  for(int i=st;i<en;i++){
    s[excount].izr[i-st]=exp[i];
    pl=0;
  }
  excount++;
}
int main(){
  cin.getline(exp,31);
  int len;
  int i,last;
  long long temp;
  len=strlen(exp);
  for(i=0;i<len;i++)
    if(i%2==0){
      exp[i]=exp[i]-'0';
    }
  temp=exp[0];
  last=0;
  for(i=1;i<len;i+=2){
    if(exp[i]=='*'){
      makenewexpr(last,i);
      last=i+1;
    }
  }

  for(i=1;i<len;i+=2){
    if(exp[i]=='+')
      temp+=exp[i+1];
    else if(exp[i]=='-')
      temp-=exp[i+1];
    else
      temp*=exp[i+1];
  }
  cout<<temp<<endl;
  return 0;
}