# include <iostream.h>
# include <math.h>

int main ()
{
	long int a,b,k,p=-1,x,y;
	double drob,A,B;
	while ((a<=0)||(b<=0)||(b<=a)||(a>=30000000)||(b>=30000000)||(k<=0)||(k>=pow (10, 18))||(p<=0)||(p>=50)) cin >> a >> b >> k >> p;
	A=(double)a;
	B=(double)b;
        drob=A/B;
	for (int u=1; u<k; u++)
	{
        	drob*=10;		
	}
	for (int i=0; i<p; i++)
	{
		y=(int)drob;
		drob=drob-(double)y;
		drob*=10;
                x=(int)drob;
		cout << x;               
	}
        return 0;
}