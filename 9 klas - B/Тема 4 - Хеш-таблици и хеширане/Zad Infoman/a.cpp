#include <iostream>

using namespace std;

unsigned char s[10];

unsigned long hash_a(unsigned char *str)
{
  unsigned int hash = 0;
  unsigned int c;
    
  while (c = *str++)
      hash = ((hash << 5) + hash) + c;
  
  return hash;
}

             

int main()
{int x=0;
while (x<=10)
{ cin>>s;
  cout<<hash_a(s)<<endl;
  x++;
 }
 return 0;
}
