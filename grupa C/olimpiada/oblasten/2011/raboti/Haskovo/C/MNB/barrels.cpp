#include<iostream>
#include<algorithm>
using namespace std;
long long int s,ost,barrel_count;
int n;
long long int barrel[200];
int main()
{
  cin>>s;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>barrel[i];
  }
  int j=n-1;
  sort(barrel,barrel+n);
  while(s>=0)
  {
    if(s==0){break;}
    if(barrel[j]<=s)
    {
      barrel_count+=s/barrel[j];
      ost=s%barrel[j];
      s=ost;
      j--;
    }
    else{j--;}
  }
  cout<<barrel_count<<endl;
  return 0;
}