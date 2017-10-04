#include<iostream>
using namespace std;

const int maxlen=100002;
const int maxint=999999999;

int a[maxlen];
int n;
int k;
int t[maxlen];


int dp(int k)
{

 //memset(t,0,maxlen*sizeof(int));
 for(int i=0;i<maxlen;i++) t[i]=0;
 t[1]=a[1];

 for(int i=2;i<=n;i++)
 {
  int m=-maxint;
  for(int p=1;p<=k;p++)
   if(i-p>=1)
    if(m<t[i-p]) m=t[i-p];
  t[i]=m+a[i];

 }

 int m=-maxint;
 int n0;
 for(int i=k;i>=1;i--)
 {
  //cout << t[n-i+1] << " ";
  if(m<t[n-i+1]) {m=t[n-i+1]; n0=n-i+1;}
 }
 //cout << endl;
 //cout << endl;
 //cout << n << " " << n0 << " " << m << endl;
 //cout << m << endl;
 return m;

}

int main()
{

 cin >> n;
 cin >> k;
 for(int i=1;i<=n;i++) cin >> a[i];
 int m=-maxint;
 int c;
 for(int j=1;j<=k;j++)
 {
   int v=dp(j);
   if(m<v){m=v;c=j;}
 }
 cout << m << " " << c << endl;
 }

