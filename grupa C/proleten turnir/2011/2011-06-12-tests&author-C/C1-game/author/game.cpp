#include<iostream>
using namespace std;

int s;
int g;
int h[2];
int a[2][1001];
bool p[2][1000001];

int main()
{
  cin >> s;
  cin >> g;
  for(int j=0;j<=1;j++)
  {
   cin >> h[j];
   for(int i=0;i<h[j];i++) cin >> a[j][i];
  }
  
  for(int k=1;k<=s;k++)
  for(int j=0;j<=1;j++)
  {
   for(int i=0;i<h[j];i++)
   if(k-a[j][i]>=0)
   if(!p[1-j][k-a[j][i]]) {p[j][k]=true; break;}
  }
 
  cout << p[g-1][s] << endl;
    
}
