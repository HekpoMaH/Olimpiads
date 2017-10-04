#include <stdio.h>

void main()
{
	long int  n,price,oldsail=0,newsail,win=0;
	int i; double x,y; char c;
	scanf("%ld %ld",&n,&price);
	for(i=0;i<=price;i++)
	{
		x=(float)i/(float)price;
		y=100*x*x; // quadratic
		//y=100*x; //linear
		//y=100;
		if (y*0.01*n>=oldsail+1)
		{
			newsail=0.01*y*n;
			win=win+(newsail-oldsail)*(price-i);
			//printf("%ld %ld %ld\n",newsail,price-i,(newsail-oldsail)*(price-i));
			oldsail=newsail;
		}
	}
	printf("%ld\n",win);
	scanf("%c",&c);
}
