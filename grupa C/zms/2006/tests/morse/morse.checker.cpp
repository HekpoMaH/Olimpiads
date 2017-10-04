#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	FILE *fo;
	FILE *fa;
	int sol, ans;
	char buf[255];
	
	if(argc != 4)
	{
		printf("argument error");
		return 0;
	}
	
	fo = fopen(argv[2],"r");
	if(fo == NULL)
	{
		printf("0\nCannot open result.\n");
		return 0;
	}
	
	fa = fopen(argv[3],"r");	
	if (fa == NULL)
	{
		printf("0\n%s\n no sol_file\n", argv[3]);
		return 0;
	}
	
	char buffer1[100], buffer2[100];

	int OK = 1;
	while (1)
	{
		int f1 = fscanf(fo, "%80s", buffer1);
		int f2 = fscanf(fa, "%80s", buffer2);
		if (f1 != f2 || strcmp(buffer1, buffer2) != 0)
		{
			OK = 0;
			break;
		}
		if (f1 <= 0 || f2 <= 0)
			break;
	}
	if (OK)
	{
		printf("10\n");
		printf("Correct solution.\n");
	}
	else
	{
		printf("0\n");
		printf("Incorrect output.\n");
	}
	
	fclose(fa);
	fclose(fo);
	return 0;
}
