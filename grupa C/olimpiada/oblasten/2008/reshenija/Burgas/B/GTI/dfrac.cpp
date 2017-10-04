#include <iostream.h>
#include<math.h>


int main()
{int a;
int b;
long long double s;
long long  double s1;
int broi=0;
int k,p;




cin>>a>>b;
 	cin>>k>>p;
 	s=1.0*a/b;
 	s1=1.0*a/b;
	 if(k==1) s=s-floor(s);
    else {
  
	do{s=s*10;
	   broi++;   
     }while(broi!=k-1);
	       }

	s=s-floor(s);

	
	broi=0;

	do { int cc=s*10;
		  cout<<cc;
        s=s*10-cc;
		 broi++;
  	   	
  		}
  while (broi!=p);  

  return 0;
}