#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
long long n,k,id,xr,br;
int idc[10000];
int main()
{
  ifstream fin("samba.in");
  ofstream fout("samba.out");
  fin>>n>>k;
  for(int i=0;i<n;i++)
  {
    fin>>id;
    for(int i=0;i<k-1;i++){xr^=id;}
  }
  //for(int i=0;i<n;i++)cout<<id[i]<<endl;
  fout<<xr<<endl;
  fin.close();
  fout.close();
  return 0;
}
