#include<iostream>
using namespace std;

long s;
int n;
long a[100];
long broi;

int main()
{
   int i;

   cin>>s>>n;
   for(i=0;i<n;i++)
      cin>>a[i];
   sort(a,a+n);


   i=n-1;
   while(i>=0)
   {
      while(a[i]<=s)
      {
         s-=a[i];
         broi++;
      }
      i--;
   }

   cout<<broi<<endl;

   return 0;
}

/*
10000 7
12 1 11 30 14 2 18

*/