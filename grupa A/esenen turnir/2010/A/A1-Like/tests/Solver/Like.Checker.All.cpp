/*
ID: espr1t
TASK: like.checker
LANG: C++
CONTEST: National Autumn Contest, Shumen 2010
AUTHOR: Alexander Georgiev
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>

#define OK 0
#define WA 1

#define MAX_NODES 1024
#define MAX_EDGES 131072

using namespace std;
FILE *in = NULL; FILE *out = NULL;

int n, m;
int degree[MAX_NODES];
int ma3x[MAX_NODES][MAX_NODES];
char ** arguments;

int check(char ** args)
{
//	fprintf(stderr, "Opening file1 = %s\n", args[1]);
//	fprintf(stderr, "Opening file2 = %s\n", args[2]);
	
	if (in != NULL) fclose(in);
	if (out != NULL) fclose(out);
	in = fopen(args[1], "rt"); // Pass input as first argument
	out = fopen(args[2], "rt"); // Pass contestant's output as second argument
	
	memset(ma3x, 0, sizeof(ma3x));
	memset(degree, 0, sizeof(degree));
	
	fscanf(in, "%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int node1, node2;
		fscanf(in, "%d %d", &node1, &node2);
		ma3x[node1][node2] = 1;
		ma3x[node2][node1] = 1;
	}
	
	char str[1024], buff[1024];
	fgets(buff, 1024, out); buff[1023] = 0;
	sscanf(buff, "%s", str);
	if (strcmp(str, "Yes"))
		return WA;
	for (int i = 0; i < m; i++)
	{
		int node1, node2;
		if (fscanf(out, "%d %d", &node1, &node2) != 2)
			return WA;
		if (node1 <= 0 || node1 > n) return WA;
		if (node2 <= 0 || node2 > n) return WA;
		if (ma3x[node1][node2] == 0) return WA;
		ma3x[node1][node2] = 0;
		ma3x[node2][node1] = 0;
		degree[node1]++;
		degree[node2]--;
	}
	for (int i = 1; i <= n; i++)
	{
		if (abs(degree[i]) > 1) return WA;
		for (int c = i + 1; c <= n; c++)
			if (ma3x[i][c]) return WA;
	}
	return OK;
}

int main(void)
{
	int numTests = 20;
	arguments = new char*[4];
	arguments[0] = "Like.Checker.All.exe";
	for (int test = 1; test <= numTests; test++)
	{
		char inpFile[32], outFile[32];
		sprintf(inpFile, "Like.%02d.in", test);
		sprintf(outFile, "Like.%02d.sol", test);
		arguments[1] = inpFile;
		arguments[2] = outFile;
		fprintf(stderr, "Checking test Nr.%02d...", test);
		int res = check(arguments);
		if (res == OK) fprintf(stderr, "OK!\n");
		if (res == WA) fprintf(stderr, "Wrong Answer!\n");
	}
	system("pause");
	return 0;
}
