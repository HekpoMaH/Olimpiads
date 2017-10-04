#include <iostream.h>
using namespace std;
int main()
{
    char ch[61];
    int N,b,a,br=0,i,r,p;
    cin >> N;
    do
    {
      cin >> ch;
      do
      {
      for(int a=0;a<=60;a++)
      if(ch[a]==' ') {
                  b=a;
                  while(b<=60)
      {           i=ch[b+1];
                  ch[b+1]=' ';
                  r=2;
                  do
                  {
                    p=ch[b+r];
                    ch[b+r]=i;
                    i=p;
                    r++;
                    }
                    while(b+r<=60);
                    b++;
                    }
                    }
                    }
                    while(ch[a]==' ');
                    
                    cout << ch << endl;
                    br++;
                    
                    }
                    while(br<N);
    return 0;
    }
    
    
    
