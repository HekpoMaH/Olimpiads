#include <iostream> // Basic input and output library
using namespace std;

int GetNextPrime(int i)
{
	int br;
	if (i>1) i--;
	do
	{
		br=0;
		i++;	
		for (int j = 2 ; j<i-1; j++)
			if (i%j==0) br++;
	
	} while (br!=0);
	return i;
}
int main()
{
	char b[51]="", c;
	int i, p , max = 0, minM=0, br, n, q, j, k;
	cin>>n;
	for (i=0;i<n;i++)
		cin>>b[i];
	for (i=1; i<1000; i=p)
	{
		p = GetNextPrime(i);
	//	cout << p <<endl;
		q = p;
		br = 0;
		//generirane na posledowatelnostta
		for (j=0; j<n; j++)
		{
			k = q-1;
			c = 'a'-1;
			do
			{
				c++; 
				if (c > 'd') c = 'a';
				k++;
			} while (k % 13 != 0);
			c++;
			if (c > 'd') c = 'a';
			//proverka za sywpadenie na poredniq generiran simvol s porednia daden
			if (b[j] == c) br++;
			q = GetNextPrime(k+1);
		}
		//proverka po-dobro postijenie do momenta
		if (max < br) {
			max = br;
			minM = i;
		}
		//proverka za nai-dobro postivenie
		if (br == n) 
			break;
		p++;
	}
	cout<< minM<<endl;
return 0; 
}
