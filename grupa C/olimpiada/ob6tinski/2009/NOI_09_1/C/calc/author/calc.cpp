#include<iostream>
#include <string>
using namespace std;
int main()
{string s;
int x=0;
cin>>s;
while (s.length()%3 >0) s='0'+s;
while (s>"")
    {x=x+(s[0]-'0')*4+(s[1]-'0')*2+(s[2]-'0');
    s.erase(0,3);
    }
if (x%7==0) cout<<"YES"<<endl;
else cout<<7-x%7<<endl;    
return 0;
}
