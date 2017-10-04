#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
stack<char> szz;
stack<long long> sc;
long long x,end;
char ch;
int main()
{
  do
  {
    scanf("%s",&ch);
    scanf("%I64d",&x);
    szz.push(ch);
    sc.push(x);
    end=x;
  }while(ch!='=');
  szz.pop();sc.pop();
  while(sc.size()>0)
  {
    ch=szz.top();
    szz.pop();
    x=sc.top();
    sc.pop();
    switch(ch)
    {
      case '*':end/=x;break;
      case '+':end-=x;break;
      case '-':end+=x;break;
    }
  }
  printf("%I64d",end);
  return 0;
}
