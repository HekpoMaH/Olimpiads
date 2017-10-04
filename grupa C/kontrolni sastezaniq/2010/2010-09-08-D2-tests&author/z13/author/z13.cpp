#include <iostream>
using namespace std;
 string s1,s2;
 long long N,A,B,C,Sum,Br,B1,mm;
 int i;
 
long long Stepen(long long k)
{
    int i;
    long long p;

    k--;
    p=1;
    for (i=1; i<=k; i++) 
      p=(p*10) % mm;

    p=(9*p) % mm;
    return p;
}

int main (){
    mm=12345678;   
    cin>>N;
    A=80; B=9; C=1;
    Sum=1;
    for (i=3;i<=N;i++)
     {
      Br=Stepen(i);
      C=C*10+B;
      C=C % mm;
      B=A+B;
      B=B % mm;
      B1=(B+C) % mm;
      if (B1>Br)
       Br=Br+mm;
      A=Br-B1;
      A=A % mm;
      Sum=(Sum+C) % mm;
    }
    cout<<Sum<<endl;
 	//system("pause");
	return 0;
}
