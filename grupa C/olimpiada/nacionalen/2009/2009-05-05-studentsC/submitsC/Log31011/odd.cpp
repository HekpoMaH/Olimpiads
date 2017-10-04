/*
TASK:odd
LANG:C++
*/
#include<iostream>
using namespace std;
int main()
{
   unsigned long long n,m,x,i;
   cin>>n>>m;
   x=m;
   for(i=2;i<=n;i++)
   {
      cin>>m;
      x=x^m;
   }
   cout<<x<<endl;
   //system("pause");
   return 0;
}
/*
TASK:odd
LANG:C++
*/
/*
#include<iostream>
using namespace std;
int main()
{
   unsigned long n,m,x,i;
   scanf("%lu%lu",&n,&m);
   x=m;
   for(i=2;i<=n;i++)
   {
      scanf("%lu",&m);
      x=x^m;
   }
   printf("%lu\n",x);
   system("pause");
   return 0;
}
*/
//11 715667 124729 124729 715667 715668 12345 12345 12345 54321 54321 12345
//9 57917 1598792 57917 1598792 57917 1598792 57917 1598792 57917
//3 191875979 191875797 191875979
