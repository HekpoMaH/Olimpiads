#include<iostream>
using namespace std;
char c[100];
long long int s[100];
int main()
{
 cin >> c;
 s[0]=(long long int)c[0]-(long long int)'0'; 

 long long int b=2;

 int i=1;
 while(c[i]!=0)
 {
  s[i]=11*s[i-1]+b*((long long int)c[i]-(long long int)'0');
  b=2*b;
  i++;
 }

 cout << s[i-1];
 cout << "\n";
 return 0;
}

