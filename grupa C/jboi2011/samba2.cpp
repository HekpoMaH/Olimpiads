#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
long long n,k,id,br=1;
int idc[100000];
int main()
{
  ifstream fin("samba.in");
  ofstream fout("samba.out");
  fin>>n>>k;
  for(int i=0;i<n;i++)
  {
    fin>>idc[i];
    //for(int i=0;i<k-1;i++){xr^=id;}
  }
  sort(idc,idc+n);
  for(int i=0;i<n-1;i++)
  {
    if(idc[i]==idc[i+1])br++;
    else
    {
      if(br%k!=0){fout<<idc[i]<<endl;break;}
      br=1;
    }
  }
  //for(int i=0;i<n;i++)cout<<id[i]<<endl;
//  fout<<xr<<endl;
  fin.close();
  fout.close();
  return 0;
}
