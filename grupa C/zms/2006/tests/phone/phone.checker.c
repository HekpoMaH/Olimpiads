#include <stdio.h>
#include <stdlib.h>

FILE *in, *out, *sol;

int main(int argc, char *argv[]) {
	int a1, a2;
	double d1, d2;

	sol = fopen(argv[3], "r");
	out = fopen(argv[2], "r");
	while (1) {
		a1 = fscanf(sol, "%lf", &d1);
		a2 = fscanf(out, "%lf", &d2);
		if (a1^a2) {
			printf("0\nDifferent number of numbers!\n");
			return 0;
		}
		if (a1!=1 && a2!=1) break;
		if (d1-d2>0.015 || d2-d1>0.015) {
			printf("0\nWrong Answer: Got %.4lf instead of %.4lf!\n", d2, d1);
			return 0;
		}
	}
	fclose(sol);
	fclose(out);
	printf("10\n");

	return 0;
}
