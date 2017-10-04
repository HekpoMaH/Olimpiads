// gcc 2.95.3
// checker for EGYPT
// call: egypt_checker <in-file> <competitor's out-file>
// output: MF, WA, OK

#include<fstream.h>

const long long int MAX=999999999;

fstream f;
long long int A,B,x,x0,a,b,a0,b0,c;

long long int euclid(long long int a, long long int b)
{
 while(a != b)
 if(a>b)a=a-b; else b=b-a;
 return a;
}

int main(int argc, char *argv[])
{
 if(argc != 3) return 1;

 f.open(argv[1],ios::in);
 f >> A >> B;
 f.close();

 f.open(argv[2],ios::in);
 if(!f){cout << "MF "; return 9;}
 f >> x;
 a=1;
 b=x;
 x0=x;
 while(!f.eof())
  {
    x=0;
    f >> x;
    if(x!=0)
     {
      if(x<=x0){cout << "WA "; return 2;}
      if(x<0){cout << "WA "; return 3;}
      if(x>MAX){cout << "WA "; return 4;}
      x0=x;
      a0=a*x+b;
      b0=b*x;
      c=euclid(a0,b0);
      a=a0/c;
      b=b0/c;
     }
  }
 f.close();
 if(a*B != b*A){cout << "WA "; return 6;}
 cout << "OK ";
 return 0;
}
