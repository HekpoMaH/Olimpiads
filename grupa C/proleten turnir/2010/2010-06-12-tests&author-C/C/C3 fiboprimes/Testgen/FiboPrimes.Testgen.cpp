#include <cstdio>
#include <cstring>

int main(void)
{
	int numTests = 20;
	for (int curTest = 1; curTest <= numTests; curTest++)
	{
		char fileName[32];
		sprintf(fileName, "FiboPrimes.%02d.in", curTest);
		FILE *out = fopen(fileName, "wt");
		
		if (curTest == 1) fprintf(out, "1\n");
		if (curTest == 2) fprintf(out, "42\n");
		if (curTest == 3) fprintf(out, "666\n");
		if (curTest == 4) fprintf(out, "1337\n");
		if (curTest == 5) fprintf(out, "1337666\n");
		if (curTest == 6) fprintf(out, "42133742\n");
		if (curTest == 7) fprintf(out, "87654321\n");
		if (curTest == 8) fprintf(out, "123456789\n");
		if (curTest == 9) fprintf(out, "987654321\n");
		if (curTest == 10) fprintf(out, "10000000000\n");
		if (curTest == 11) fprintf(out, "41467334500\n");
		if (curTest == 12) fprintf(out, "281827961491\n");
		if (curTest == 13) fprintf(out, "995942827436\n");
		if (curTest == 14) fprintf(out, "703811322333\n");
		if (curTest == 15) fprintf(out, "999000001289\n");
		if (curTest == 16) fprintf(out, "999999999599\n");
		if (curTest == 17) fprintf(out, "999999998527\n");
		if (curTest == 18) fprintf(out, "10000000001\n");
		if (curTest == 19) fprintf(out, "100000000001\n");
		if (curTest == 20) fprintf(out, "1000000000000\n");
		fclose(out);
	}
	return 0;
}


