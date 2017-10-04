//Task: Puzzles
//Author: Stoyan Kapralov

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main () 
{ string s,x;
  int t[20], y[5]={0,1,2,3,4};
  int n,k;
  
  cin >> s;
  n = s.size();
  
  int i=1;
  while(s[i]!='+') i++;
  int j=i+1;
  while(s[j]!='=') j++;
  int plus = i, equ = j;
  
  for(int i=0; i<26; i++)
  { char c = 'A'+i;
    if(s.find(c)!=string::npos) x = x + c;
  }
  k = x.size();
    
  int cnt = 0; 
  bool last;
  do
  { 
    do
    { for(int i=0; i<n; i++)
      { if('A'<=s[i] && s[i]<='Z')
        { int p=x.find(s[i]);
          t[i] = y[p];
        }
        else if('0'<=s[i] && s[i]<='9')
          t[i] = s[i] - '0';
      }
      
      if(t[0]>0 && t[plus+1]>0 && t[equ+1]>0)
      { int a=0,b=0,c=0;
        for(int i=0; i<plus; i++)     a = a*10 + t[i];
        for(int i=plus+1; i<equ; i++) b = b*10 + t[i];
        for(int i=equ+1; i<n; i++)    c = c*10 + t[i];
        if(a+b==c)
        { cnt++; 
//          cout << cnt << ") " << a << "+" << b << "=" << c << endl; 
        }  
      }
    } while(next_permutation(y,y+k));
      
    int i=k-1;
    while(i>=0 && y[i]==10-k+i) i--;
    if(i<0) last = true;
    else
    { last = false;
      y[i]++;
      for(int j=i+1; j<k; j++)
        y[j] = y[j-1]+1;
    }

  } while(!last);
    
  cout << cnt << endl;
   
  return 0;
}
