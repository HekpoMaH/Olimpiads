#include<iostream>
#include<stack>
using namespace std;
bool flag=false;
int leftbr,rigthbr;
string Izraz;
long long CalcRes( string Izraz )
{
  long long Res;
  stack<char> Op;
  stack<long long> Num;
  for (unsigned short i = 0; i < Izraz.size();i++)
  {
    if ( Izraz[i] != ')' && !(Izraz[i] >= '0' && Izraz[i]<= '9'))
    {
      Op.push(Izraz[i]);
    }
    else
    if (Izraz[i] == ')')
    {
      if (Op.top() == '(')
      {
        flag = true;
        return 0;
      }
      switch(Op.top())
      {
        case('*'):
        {
          long long a = Num.top();
          Num.pop();
          Num.top() *= a;
          break;
        }
        case('-'):
        {
          long long a = Num.top();
          Num.pop();
          Num.top() -= a;
          break;
        }
        case('+'):
        {
          long long a = Num.top();
          Num.pop();
          Num.top() += a;
          break;
        }
      }
      Op.pop();
      Op.pop();
    }
    else
    {
      Num.push(Izraz[i]-'0');
    }
  }
  switch(Op.top())
  {
      case('*'):
      {
        long long a = Num.top();
        Num.pop();
        Num.top() *= a;
        break;
      }
      case('-'):
      {
        long long a = Num.top();
        Num.pop();
        Num.top() -= a;
        break;
      }
      case('+'):
      {
        long long a = Num.top();
        Num.pop();
        Num.top() += a;
        break;
      }
  }
  return Num.top();
}
bool Breackets(string Izraz)
{
  short leftcount=0,rigthcount=0;
  for (unsigned short i = 0; i < Izraz.size();i++)
  {
    if ( Izraz[i] == ')' )
      rigthcount++;
    if ( Izraz[i] == '(' )
      leftcount++;
    if (rigthcount > leftcount)
      return false;
  }
  return true;
}
long long rec(string Izraz,int pos,bool& flag2)
{
  pos++;
  long long Res;
  if (!rigthbr && !leftbr)
  {
    if (Breackets(Izraz))
    {
      CalcRes(Izraz);
      flag2 = flag;
      flag = false;
      return Res;
    }
    else
      flag2 = true;
  }
  if ((Izraz[pos]>='0' && Izraz[pos]<='9')|| (Izraz[pos]==')'))
  {
    bool Ok,Ok1;
    long long Res2;
    Res = rec(Izraz,pos,Ok);
    if ((pos+1 == Izraz.size())||(!rigthbr))
    {
      flag2 = Ok;
      return Res;
    }
    rigthbr--;
    Res2 = rec(Izraz.substr(0,pos+1) + ')' + Izraz.substr(pos+1,Izraz.size()-pos-1),pos,Ok1);
    flag2 = Ok||Ok1;
    rigthbr++;
    if (Ok1)
      return Res;
    if (Ok)
      return Res2;
    if (!Ok && !Ok1 )
      return min(Res,Res2);
  }
  if (Izraz[pos]== '-' || Izraz[pos]=='+'|| Izraz[pos]=='*' || Izraz[pos]=='(')
  {
    bool Ok,Ok1;
    long long Res2;
    Res = rec(Izraz,pos,Ok);
    if ((pos+1 == Izraz.size())||(!leftbr))
    {
      flag2 = Ok;
      return Res;
    }
    leftbr--;
    Res2 = rec(Izraz.substr(0,pos+1) + ')' + Izraz.substr(pos+1,Izraz.size()-pos-1),pos,Ok1);
    flag2 = Ok||Ok1;
    leftbr++;
    if (Ok1)
      return Res;
    if (Ok)
      return Res2;
    if (!Ok && !Ok1 )
      return min(Res,Res2);
  }
  return rec(Izraz,pos,flag2);
}
int main()
{
  cin >> Izraz;
  rigthbr=leftbr = (Izraz.size()-1)/2 -1;
  bool outflag;
  cout << rec(Izraz,0,outflag) << "\n";
  return 0;
}
