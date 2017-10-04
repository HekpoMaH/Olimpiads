#include <iostream>
using namespace std;
int main()
{long long a,b,p,q,t,r;
 int n,d,c,e,f;
 cin>>a>>b>>n>>d;
 //Най-голям общ делител (НОД) на n и d
 e=d;f=n;//временни променливи
 do
 {c=e%f;
  if (!c) break;
  e=f;
  f=c;
 }while (true);
 //Тук НОД е в f
 n/=f;d/=f;//Съкращаваме на f
 c=0;//Брояч на намерените дроби
 //Търсим първото p в интервала [a,b]
 t=a/n;//t ще става първият множител, за който pt>=a
 if (a%n) t++;//Ако не се дели точно - следващото
 p=t*n;q=t*d;//дробта p/q=n/d
 while (p<=b)
 {
   r=0;//В r ще запишем p "обратно"
   while (p)
   {r=10*r+p%10;
    p/=10;
   }
   if (r==q) c++; //Ако обратното на p е точно q - броим
   t++;
   p=t*n;q=t*d;//следващата дроб
 }
 cout<<c<<endl;
 return 0;
}
