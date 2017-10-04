#include <iostream>
#include <cstring>
using namespace std;
int const MAX=30;
char a[MAX][MAX+1];
int M,N;
int main()
{cin>>N;
 for (int i=0;i<N;i++) cin>>a[i];
 M=strlen(a[0]);
 int c=0,cc=a[0][0]-'0'+a[0][M-1]-'0'+a[N-1][0]-'0'+a[N-1][M-1]-'0';
 for (int i=0;i<N;i++)
  for (int j=0;j<M;j++) if (a[i][j]=='1') c++;
 if (M<3 || N<3) {cout<<c<<endl; return 0;}
 cout<<min(c,2*(M+N)-8+cc)<<endl;
 return 0;
}
