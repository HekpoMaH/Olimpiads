#include <iostream>
#include <string>
using namespace std;
string s,sr;
int main()
{
 cin>>s;
 int d=s.length();
 for(int i=0;i<d;i++) sr += s[d-i-1];
 for(int i=0;i<d;i++)
 {
   if(s[i]==s[d-1]&&s.substr(i,(d-i)/2)==sr.substr(0,(d-i)/2)){cout<<i<<endl;break;}
 }
 return 0;
}
