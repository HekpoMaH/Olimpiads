#include <iostream>
#include <fstream>

using namespace std;

long long getTime(string s)
{ int p = s.find(":");
  s.erase(0,p+1);
  while(s[0]==' ') s.erase(0,1);
  if(s.size()<11) s = "0" + s;
  long long h = (s[0]-'0')*10+(s[1]-48);
  long long min = (s[3]-'0')*10+(s[4]-48);
  long long sec = (s[6]-'0')*10+(s[7]-48);
  long long ms =  (s[9]-'0')*10+(s[10]-48);
  long long t = (((h*60)+min)*60+sec)*100+ms;   
  return t;    
}     

int main()
{ string s,s1,s2;
  
  ifstream fin("time.txt");
  getline(fin,s1);
  getline(fin,s);
  getline(fin,s2);
  fin.close();
  
//  cout << "Time: " << getTime(s2) - getTime(s1) << endl;
  cout << "Time= " << getTime(s2) - getTime(s1) << endl;
  
  return 0; 
}

