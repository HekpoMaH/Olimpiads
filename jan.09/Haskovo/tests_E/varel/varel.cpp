#include<iostream>
using namespace std;

int v,c,n;

int main()
{
  cin >> v;
  cin >> c;
  cin >> n;
  for(int i=1;i<=n;i++)
  {
    char s;
    cin >> s;
    if(s=='+') v = v+c;
    if(s=='-') v = v-c;
    
    if(v<=0) cout << "error\n";
    
  }
    
  cout << v << endl;  
    
}
