#include<iostream>
#include<set>
using namespace std;

int s;
const int s_max=20000002;
int a[s_max];

int main()
{
  cin >> s;
  for(int i=1;i*i<=s;i++) 
    for(int j=0;i*i+j*j<=s && j<=i;j++) a[i*i+j*j]++;
  int c=0;
  for(int k=1;k<=s;k++) if(a[k]>0) c++;
  cout << c << endl;  
}


