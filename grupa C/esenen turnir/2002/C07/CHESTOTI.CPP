//Peter Ivanov 7klas Shumen PMG tel. 52331
#include<iostream.h>
#include<string.h>
void main ()
{  int N;
   char A, G;
   char X=0,Y=0;
   int x=0,y=0;
   cin>>N;
   for (int i=0; i<N; i++)
   {  cin>>A;
      for (int j=0; j<strlen(A); j++)
      {  G=A[j];
	 for (int k=j+1; k<strlen(A); k++)
	    if (G==A[k]) {X=G; x++;}
	 if (x>=y) {Y=X; y=x;}
      }
   }
   cout<<Y<<' '<<y;
}
