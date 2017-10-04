/*
TASK:money
LANG:C++
*/
#include<iostream>
#include<vector>
using namespace std;
long n,m,i,j,ij,br,
maxbr;
vector <long> a;
int main()
{
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
      scanf("%d",&m);
      a.push_back(m);
   }
   sort(a.begin(),a.end());
   for(i=0;i<=n-2;i++)
   {
      for(j=i+1;j<=n-1;j++)
      {
         for(ij=n-1;ij>=i+1;ij--)
         {
            if (a[i]+a[j]>a[ij]) 
            {
               br=(ij-j)+2;
               if (br>maxbr) {maxbr=br;}
               break;
            }
         }
      }
   }
   if (maxbr>2) {printf("%d\n",maxbr);}
   else {printf("1\n");}
   //system("pause");
   return 0;
}
