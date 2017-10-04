#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_NODES 1000
#define MAX_EDGES 100000
FILE *out;

int n, m;
int edges[MAX_EDGES][2];
int ma3x[MAX_NODES][MAX_NODES];

void addEdge(int node1, int node2)
{
	edges[m][0] = node1;
	edges[m][1] = node2;
	m++;
}

void sampleInput()
{
	fprintf(stderr, "Generating sampleInput()...\n");
	n = 5; m = 0;
	addEdge(1, 2);
	addEdge(1, 3);
	addEdge(1, 4);
	addEdge(1, 5);
	addEdge(2, 3);
	addEdge(4, 5);
	addEdge(3, 5);
}

void simpleTest1()
{
	fprintf(stderr, "Generating simpleTest1()...\n");
	n = 4; m = 0;
	addEdge(1, 2);
	addEdge(1, 3);
	addEdge(1, 4);
	addEdge(2, 3);
	addEdge(2, 4);
}

void simpleTest2()
{
	fprintf(stderr, "Generating simpleTest2()...\n");
	n = 11; m = 0;
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(3, 4);
	addEdge(4, 1);
	addEdge(2, 5);
	addEdge(5, 6);
	addEdge(6, 7);
	addEdge(7, 8);
	addEdge(8, 5);
	addEdge(9, 10);
	addEdge(10, 11);
}

void multipleOdd()
{
	fprintf(stderr, "Generating multipleOdd()...\n");
	// Make 5 "stars"
	n = 20; m = 0;
	for (int group = 0; group < 5; group++)
	{
		addEdge(group * 4 + 1, group * 4 + 2);
		addEdge(group * 4 + 1, group * 4 + 3);
		addEdge(group * 4 + 1, group * 4 + 4);
	}
}


void noOdd(int n_, int m_)
{
	fprintf(stderr, "Generating noOdd() with arguments (%d, %d)...\n", n_, m_);

	n = n_; m = 0;
	int each = (m_ * 2) / n_;

	int cnt[MAX_NODES];
	memset(cnt, 0, sizeof(cnt));
	memset(ma3x, 0, sizeof(ma3x));
	
	int next = n - 1;
	for (int i = 0; i < n - 1; i++)
	{
		while (cnt[i] < each)
		{
			/*
			int idx = rand() % n;
			while (idx == i || cnt[idx] >= each || ma3x[i][idx])
				idx = rand() % n;
			*/
			if (next <= i) next = n - 1;
			int idx = next--;
			ma3x[i][idx] = 1; cnt[i]++;
			ma3x[idx][i] = 1; cnt[idx]++;
			addEdge(i + 1, idx + 1);
		}
	}
}

void completelyConnected(int n_)
{
	fprintf(stderr, "Generating completelyConnected() with argument %d...\n", n_);
	n = n_; m = 0;
	for (int i = 0; i < n; i++)
		for (int c = i + 1; c < n; c++)
			addEdge(i + 1, c + 1);
}

void randTest()
{
	n = rand() % (MAX_NODES - 50) + 51; m = 0;

	int lim = n * (n - 1) / 2;
	int numEdges = ((rand() + rand() + rand()) % lim + 201) % (MAX_EDGES - 200) + 201;
	
	fprintf(stderr, "Generating randTest() with arguments (%d, %d)...\n", n, numEdges);
	
	memset(ma3x, 0, sizeof(ma3x));
	for (int i = 0; i < numEdges; i++)
	{
		int idx1 = rand() % n;
		int idx2 = rand() % n;
		if (idx1 == idx2) continue;
		if (ma3x[idx1][idx2]) continue;

		ma3x[idx1][idx2] = 1;
		ma3x[idx2][idx1] = 1;
		addEdge(idx1 + 1, idx2 + 1);
	}
}

void printTest(int curTest)
{
	char fileName[32];
	sprintf(fileName, "Like.%02d.in", curTest);
	out = fopen(fileName, "wt");
	fprintf(out, "%d %d\n", n, m);
	for (int i = 0; i < m; i++)
		fprintf(out, "%d %d\n", edges[i][0], edges[i][1]);
	fclose(out);
	
	memset(ma3x, 0, sizeof(ma3x));
	for (int i = 0; i < m; i++)
	{
		if (edges[i][0] <= 0 || edges[i][0] > n)
			fprintf(stderr, "Error in test %d. Index out of bounds.\n");
		if (edges[i][1] <= 0 || edges[i][1] > n)
			fprintf(stderr, "Error in test %d. Index out of bounds.\n");		
		if (ma3x[edges[i][0] - 1][edges[i][1] - 1])
			fprintf(stderr, "Error in test %d. Edge already existing.\n");

		ma3x[edges[i][0] - 1][edges[i][1] - 1] = 1;
		ma3x[edges[i][1] - 1][edges[i][0] - 1] = 1;
	}	
}

int main(void)
{
	srand(42);
	int numTests = 20;
	for (int test = 1; test <= numTests; test++)
	{
		if (test == 1) sampleInput();
		if (test == 2) simpleTest1();
		if (test == 3) simpleTest2();
		if (test == 4) multipleOdd();
		if (test == 5) noOdd(15, 20);
		if (test == 6) noOdd(20, 20);
		if (test == 7) noOdd(150, 1500);
		if (test == 8) noOdd(500, 5000);
		if (test == 9) completelyConnected(300);
		if (test == 10) completelyConnected(440);
		if (test >= 11) randTest();		
		printTest(test);
	}
	fprintf(stderr, "Finished with generating tests.\n");
	system("pause");
	return 0;
}
