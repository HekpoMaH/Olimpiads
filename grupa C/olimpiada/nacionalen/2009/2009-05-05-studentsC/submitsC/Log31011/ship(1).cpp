/*
TASK:ship
LANG:C++
*/
#include<iostream>
using namespace std;
long long n,m,i,sum;
int main()
{
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
      scanf("%d",&m);
      sum=sum+m;
   }
   for(i=1;i<=n;i++)
   {
      scanf("%d",&m);
   }
   printf("%d\n",sum);
   //system("pause");
   return 0;
}
