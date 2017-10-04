#include<stdio.h>
int main()
{
unsigned long k;
scanf("%d",&k);
if (k<10) printf("%ld",k);
else if (k<100)
       {
       if (k%2==1) printf("%ld",((k-9)%2+(k-9)/2)%10-1);
	 else printf("%ld",((k-9)%2+(k-9)/2+9)/10);
       }
else printf("5");
return 0;
}