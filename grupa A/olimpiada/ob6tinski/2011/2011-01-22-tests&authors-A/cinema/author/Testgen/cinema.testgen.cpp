#include <cstdio>
#include <cstdlib>

int main(void)
{
	FILE *out = fopen("cinema.in", "wt");
	
	srand(9);
	
	int n = 10 + rand() % 90;
	int m = 10 + rand() % 90;
	int r = 1 + rand() % (n / 2);
	int c = 1 + rand() % (m / 2);

	fprintf(out, "%d %d\n", n, m);
	fprintf(out, "%d %d\n", r, c);
	
	int occ = 5 + rand() % 20;
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < m; col++)
			fprintf(out, "%c", rand() % occ == 0 ? '#' : '.');
		fprintf(out, "\n");
	}	
	return 0;
}
