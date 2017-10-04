#include<iostream>
#include<string>
using namespace std;
int n;
string a[]={
            "I","X","C","M",
            "II","XX","CC","MM",
            "III","XXX","CCC","MMM",
            "IV","XL","CD"," ",
            "V","L","D"," ",
            "VI","LX","DC"," ",
            "VII","LXX","DCC"," ",
            "VIII","LXXX","DCCC"," ",
            "IX","XC","CM"," "};
string str[7];
int ch,an,poz;
int main()
{
  cin>>an;
  poz=0;
  do
  {
    str[poz]="";
    ch=an%10;
    poz++;
    if(ch>0)
    {
      n=(ch-1)*4+poz-1;
      str[poz-1]=a[n];
    }
    an=an/10;
  }while(an!=0);
  for(int i=poz-1;i>=0;i--)cout<<str[i];
  cout<<endl;
  return 0;
}
