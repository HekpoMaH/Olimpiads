#include<iostream>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<iomanip>
using namespace std;
double pi=(double)3.14159265;
double o1x,o1y,o2x,o2y,s;
double R1,r1,R2,r2;
int main()
{
  ifstream fin ("circles.in");
  ofstream fout ("circles.out");
  fin>>o1x>>o1y>>r1>>R1;
  fin>>o2x>>o2y>>r2>>R2;
  cout<<r1<<" "<<r2<<" "<<R1<<" "<<R2<<endl;
  s=((R1*R1-r1*r1)+(R2*R2-r2*r2))*pi;
  //cout<<(R1*R1*pi-r1*r1*pi)+(R2*R2*pi-r2*r2*pi)<<endl;
  fout<<setiosflags(ios::fixed)<<setprecision(6)<<s<<endl;
  fin.close();fout.close();
  return 0;
}
