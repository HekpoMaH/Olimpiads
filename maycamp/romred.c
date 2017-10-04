#include<iostream>
#include<string>
using namespace std;
int main()
{
  string romred;
  string r[7];
  int n,m,i2,ch,poz=0,k;
  cin>>m>>n;
  string rom[]={
               "I","X","C","M",
               "II","XX","CC","MM",
               "III","XXX","CCC","MMM",
               "IV","XL","CD"," ",
               "V","L","D"," ",
               "VI","LX","DC"," ",
               "VII","LXX","DCC"," ",
               "VIII","LXXX","DCCC"," ",
               "IX","XC","CM"," "};
  for(int i=0;i<m;i++)
  {
    i2=i;
    poz=0;
    ch=0;
    do
    {
    ch=i2%10;
    poz++;
    if(ch>0)
    {
      k=(ch-1)*4+poz-1;
      r[poz-1]=rom[k];
    }
    i2/=10;
    }
    while(i2>0);
    for(int i=poz-1;i>=0;i--)romred+=r[i];
  }
  cout<<romred[n]<<endl;
  return 0;
}
