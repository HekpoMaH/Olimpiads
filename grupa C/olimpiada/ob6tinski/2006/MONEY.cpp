#include<iostream>
#include<iomanip>
using namespace std;
double pari;
double kurs;
int main()
{
  cin>>pari>>kurs;
  pari*=kurs;
  cout<<(int)pari/100<<" ";
  pari-=(int)(pari/100)*100;//cout<<pari<<" ";
  cout<<(int)pari/50<<" ";
  pari-=(int)(pari/50)*50;
  cout<<(int)pari/20<<" ";
  pari-=(int)pari/20*20;
  cout<<(int)pari/10<<" ";
  pari-=(int)pari/10*10;
  cout<<(int)pari/5<<" ";
  pari-=(int)pari/5*5;
  cout<<(int)pari/2<<endl;
  pari-=(int)pari/2*2;
  cout<<setiosflags(ios::fixed)<<setprecision(2)<<pari<<endl;
  return 0;
}
