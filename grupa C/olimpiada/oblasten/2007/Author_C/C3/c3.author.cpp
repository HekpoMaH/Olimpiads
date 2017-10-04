#include <iostream>
#include <string>

using namespace std;

const int M = 100, N = 200;

int a[M], x[M];
int y[N], b[N];

void str2num(string s, int a[])
{ int m = s.size();
  for(int i=0; i<m; i++) a[i] = s[m-1-i] - '0';
}

void mul(int a[], int x[], int y[])
{ for(int i=0; i<N; i++) y[i] = 0;

  for(int i=0; i<M; i++)
    for(int j=0; j<M; j++)
      y[i+j] += a[i]*x[j];

  int c = 0;
  for(int i=0; i<N; i++)
  { int z = y[i] + c;
    y[i] = z % 10;
    c = z / 10;
  }
}

bool less_than(int y[], int b[])
{ int i = N-1;
  while(i>=0 && y[i]==b[i]) i--;
  if(i<0) return false;
  if(y[i]>b[i]) return false;
  return true;
}

int main()
{ string s;
  cin >> s; str2num(s,a);
  cin >> s; str2num(s,b);
  for(int i=0;i<M;i++)cout<<a[i];
  cout<<endl;
  for(int i=0;i<M;i++)cout<<b[i];
  cout<<endl;
  for(int i=M-1; i>=0; i--)
  { x[i] = 0;
    do
    { x[i]++;
      mul(a,x,y);
    } while(less_than(y,b));
    x[i]--;
  }

  int i=M-1;
  while(i>0 && x[i]==0) i--;
  for(int j=i; j>=0; j--)
    cout << x[j];
  cout << endl;

  return 0;
}




