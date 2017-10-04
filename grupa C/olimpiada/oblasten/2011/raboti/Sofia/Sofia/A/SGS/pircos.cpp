#include<iostream>
using namespace std;
int main()
{
  int l=0,N; cin >> N;
  unsigned long long int a[200000],planet1,planet2;
  bool quest1=true,quest2=true;
  if(N<=200000){
  for(int i=0;i<N;i++) cin >> a[i];
  while(quest1==true){
  quest1=false;
  for(int m=0;m<N;m++) if(a[l]==a[m] && l!=m) quest1=true;
  if(quest1==false) planet1=a[l];
  l++;
  }
  while(quest2==true){
  quest2=false;
  for(int m=0;m<N;m++) if(a[l]==a[m] && l!=m) quest2=true;
  if(quest2==false) planet2=a[l];
  l++;
  }
  if(planet1<planet2) cout << planet1 << " " << planet2 << endl;
  else cout << planet2 << " " << planet1 << endl;}
  return 0;
}