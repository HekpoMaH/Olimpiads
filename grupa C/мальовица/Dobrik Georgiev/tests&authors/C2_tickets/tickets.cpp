#include <iostream>
#include <math.h>
using namespace std;
long max(long a,long b,long c)//������ max �� ��� �����
{ if (a>b && a>c) return a;
   else if(b>c) return b;
         else return c;
}
int main()
{ long a,b,c,br,s,s1,br_c,j,k,n, b1,c1;
cin>>a>>b>>c;
cin>>br>>s;
n=br+1;  b1=b-a; c1=c-a;
s1=s-br*a; //��������� ��������, ��� ������ ������ �� �� ���-��������
br_c=s1/c1;
for (long i=br_c; i>=0; i--)
{  j=(s1-i*c1)/b1;
   if (i*c1+j*b1==s1 ) //����� ���� �� ��-������� ������
      { k=br-i-j;
	      if (abs(j-i)<n && abs(j-k)<n && abs(k-i)<n)//����� ���-������������ ��������� �� ��������
	                   n=max(abs(i-j),abs(i-k),abs(k-j));
       }
 }
  cout<< n<<endl;
  }
