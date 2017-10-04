#include<iostream>
using namespace std;

string c="1", s="0";

int main()
{
  int n,m;
  cin >> n >> m;
  
  while(s.size()<99999)
  {
    s=s+c;
    c=c+"0";
  } 
  cout << s[n] << endl;
  cout << s[m] << endl;
}
