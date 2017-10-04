#include <iostream.h>
#include <math.h>
void sort(char a[], int n)
{
	int sm, temp;
	for (int i=0; i<n; i++)
	{
		for (int j=i+1; j<n;j++)
		{
			sm=1;
			if (a[j]<a[sm])
			{
				temp = a[sm];
				a[sm]=a[j];
                                a[j]=temp;
                        }
		}
	}
}


int main ()
{
	int S,N,temps,temp=0,sm=5000,q;
        cin >> S >> N;
	char vid[1000];
	for (int u=0; u<N; u++)
	{
        	cin >> vid[u];
	}
	sort (vid, N);
        temps=S;
        int n=1;
	while (temps>0)
	{
		if (temps>=vid[N-n])
		{
                        q=(int)(vid[N-n]-'0');
                        temps-=q;
			temp++;	
		}
		else n++;
                if (n>N) n=N;
	}	 
	if (temp<sm)
        {
		sm=temp;
	}
	if (S=1) sm=1;
	if (N=1) sm=S;
        cout << sm;
        return 0;
}