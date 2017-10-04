#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s="ABCDEFGHIJ";
void code(string &giv,int k){
   string s1=giv.substr(0,k);
   string s2=giv.substr(k,giv.size()-k);
   reverse(s2.begin(),s2.end());
   giv=s2+s1;
}
int main(){
   for(int i=1;i<=2013;i++){
      code(s,3);
      code(s,7);
      code(s,6);
      code(s,5);
      code(s,2);
      if(i<=2)cout<<s<<endl;
      if(i==10)cout<<s<<endl;
      if(i==2013)cout<<s<<endl;
   }
}

