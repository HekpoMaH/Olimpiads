#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string s1,s2;
int i=1,n;

int main()
{
	cin>>s1;
	n=s1.size();
	s2=s1;
	reverse(s2.begin(),s2.end());
	while(s1.substr(i,n-i)!=s2.substr(0,n-i))i++;
	s1+=s2.substr(n-i,i);
	cout<<s1<<endl;
	return 0;
}