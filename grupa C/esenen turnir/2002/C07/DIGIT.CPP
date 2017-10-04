//Peter Ivanov 7klas Shumen PMG tel. 52331
#include<iostream.h>
void main()
{  long K;
   int a, k, i;
   cin>>K;
   if (K<10) cout<<K;
   else
      if (K<100)
      {  i=9; k=9;
      do
      {  i++; k++;
	 a=i/10;
	 if (k==K) cout<<a;
	 k++;
	 a=i%10;
	 if (k==K) cout<<a;
      } while (i!=K); }
      else
	 if (K<1000)
	 {  i=99; k=99;
	 do
	 {  i++; k++;
	    a=i/100;
	    if (k==K) cout<<a;
	    k++;
	    a=(i/10)%10;
	    if (k==K) cout<<a;
	    k++;
	    a=i%10;
	    if (k==K) cout<<a;
	 } while (i!=K);}
	 else
	    if (K<10000)
	    {  i=999; k=999;
	    do
	    {  i++; k++;
	       a=i/1000;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/100)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/10)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=i%10;
	       if (k==K) cout<<a;
	 } while (i!=K);}
	 else
	    if (K<100000)
	    {  i=9999; k=9999;
	    do
	    {  i++; k++;
	       a=i/10000;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/1000)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/100)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/10)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=i%10;
	       if (k==K) cout<<a;
	 } while (i!=K);}
	 else
	    if (K<1000000)
	    {  i=99999; k=99999; cout<<"Please wait...";
	    do
	    {  i++; k++;
	       a=i/100000;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/10000)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/1000)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/100)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/10)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=i%10;
	       if (k==K) cout<<a;
	 } while (i!=K);}
	 else
	    if (K<10000000)
	    {  i=999999; k=999999; cout<<"Please wait...";
	    do
	    {  i++; k++;
	       a=i/1000000;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/100000)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/10000)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/1000)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/100)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/10)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=i%10;
	       if (k==K) cout<<a;
	 } while (i!=K);}
	 else
	    if (K<100000000)
	    {  i=9999999; k=9999999; cout<<"Please wait...";
	    do
	    {  i++; k++;
	       a=i/10000000;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/1000000)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/100000)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/10000)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/1000)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/100)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=(i/10)%10;
	       if (k==K) cout<<a;
	       k++;
	       a=i%10;
	       if (k==K) cout<<a;
	 } while (i!=K);}
}