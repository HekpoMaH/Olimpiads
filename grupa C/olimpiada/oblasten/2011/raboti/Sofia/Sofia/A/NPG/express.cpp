#include <iostream>
#include <string.h>
using namespace std;

int ctoi(char a);
int resulta (int begin,int end,char art[]);
int fr=0;
int main()
{
  char art[35];
  int size,res;
  cin.getline(art,35);
  size=strlen(art);
  res=resulta (0,size-1,art);
  cout<<res;
  return 0;
}
int resulta (int begin,int end,char art[])
{
  int res=0;
  if(begin==end)
  {
    return ctoi(art[end]);
  }
  if(art[begin+1]=='-')
  {
    res += resulta(begin,begin,art) - resulta(begin+2,end,art);
  }
  if(art[begin+1]=='+')
  {
    res += resulta(begin,begin,art) + resulta(begin+2,end,art); 
  }
  if(art[begin+1]=='*')
  {
    res += resulta(begin,begin,art) * resulta(begin+2,end,art);  
  }
  return res;
  
}
int ctoi(char a)
{
  if(a=='0')return 0;
  if(a=='1')return 1;
  if(a=='2')return 2;
  if(a=='3')return 3;
  if(a=='4')return 4;
  if(a=='5')return 5;
  if(a=='6')return 6;
  if(a=='7')return 7;
  if(a=='8')return 8;
  if(a=='9')return 9;
  return -1;
}
  