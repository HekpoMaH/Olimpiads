#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

#define MAX_N 50
#define MAX_M 2500
using namespace std;

struct Test
{
	int n, m;
	bool isFriday;
	vector < vector <int> > edges;
	
	Test()
	{
		edges.resize(MAX_M);
		for (int i = 0; i < (int)edges.size(); i++)
			edges[i].resize(3);
	}
};

vector <Test> curTest, tcTests;

void sampleInput()
{
	Test add;
	add.n = 5; add.m = 5;
	add.edges[0][0] = 1; add.edges[0][1] = 2; add.edges[0][2] = 1;
	add.edges[1][0] = 1; add.edges[1][1] = 3; add.edges[1][2] = 2;
	add.edges[2][0] = 2; add.edges[2][1] = 4; add.edges[2][2] = 1;
	add.edges[3][0] = 3; add.edges[3][1] = 4; add.edges[3][2] = 3;
	add.edges[4][0] = 4; add.edges[4][1] = 5; add.edges[4][2] = 11;
	add.isFriday = true;
	curTest.push_back(add);
	
	add.n = 2; add.m = 1;
	add.edges[0][0] = 1; add.edges[0][1] = 2; add.edges[0][2] = 26;
	add.isFriday = true;
	curTest.push_back(add);
	
	add.n = 3; add.m = 3;
	add.edges[0][0] = 1; add.edges[0][1] = 1; add.edges[0][2] = 7;
	add.edges[1][0] = 1; add.edges[1][1] = 2; add.edges[1][2] = 26;
	add.edges[2][0] = 2; add.edges[2][1] = 3; add.edges[2][2] = 16;
	add.isFriday = false;
	curTest.push_back(add);
}

vector <string> parseVectorString(FILE* in)
{
	vector <string> ret;

	char ch = '?';
	while (!feof(in) && ch != '{')
		fscanf(in, "%c", &ch);
	while(!feof(in))
	{
		fscanf(in, "%c", &ch);
		if (ch == '}') break;
		if (ch == '"')
		{
			string add;
			fscanf(in, "%c", &ch);
			while (ch != '"')
			{
				add.push_back(ch);
				fscanf(in, "%c", &ch);
			}
			ret.push_back(add);
		}
	}
	return ret;
}

void parseTests()
{
	tcTests.clear();
	FILE* in = fopen("Friday.tests", "rt");
	int numTests;
	fscanf(in, "%d", &numTests);
	for (int test = 0; test < numTests; test++)
	{
		Test add;
		vector <string> vs = parseVectorString(in);

		add.n = vs.size();
		add.m = 0;
		for (int i = 0; i < (int)vs.size(); i++)
		{
			for (int c = 0; c < (int)vs[i].size(); c++)
			{
				if (vs[i][c] == '#') continue;
				add.edges[add.m][0] = i + 1;
				add.edges[add.m][1] = c + 1;
				if (vs[i][c] >= 'A' && vs[i][c] <= 'Z')
					add.edges[add.m][2] = vs[i][c] - 'A' + 1;
				if (vs[i][c] >= 'a' && vs[i][c] <= 'z')
					add.edges[add.m][2] = vs[i][c] - 'a' + 27;
				add.m++;
			}
		}
		tcTests.push_back(add);
	}
}

void randomTest(int n_)
{
	Test add;
	add.n = n_;
	add.m = 0;
	for (int i = 1; i <= n_; i++)
	{
		for (int c = 0; c < 5; c++)
		{
			int nxt = min(add.n, max(1, i + rand() % 10 - 5));
			add.edges[add.m][0] = i;
			add.edges[add.m][1] = nxt;
			add.edges[add.m][2] = rand() % 100 + 1;
			add.m++;
		}
	}
	curTest.push_back(add);
	
	while (curTest.size() < 10)
		curTest.push_back(tcTests[rand() % (int)tcTests.size()]);
}

void largeNumberOfEdgesFromSingleNode()
{
	Test add;
	add.n = MAX_N;
	add.m = 0;
	for (int i = 1; i <= add.n; i++)
	{
		for (int c = 0; c < 5; c++)
		{
			int nxt = min(add.n, max(1, i + rand() % 10 - 5));
			add.edges[add.m][0] = i;
			add.edges[add.m][1] = nxt;
			add.edges[add.m][2] = rand() % 100 + 1;
			add.m++;
		}
	}
	while (add.m < MAX_M)
	{
		int nxt = min(add.n, max(1, MAX_N / 2 + rand() % 20 - 10));
		add.edges[add.m][0] = MAX_N / 2;
		add.edges[add.m][1] = nxt;
		add.edges[add.m][2] = rand() % 52 + 1;
		add.m++;
	}
	curTest.push_back(add);
	
	while (curTest.size() < 10)
		curTest.push_back(tcTests[rand() % (int)tcTests.size()]);
}

void printTest(int test)
{
	int goodFlag = 1;
	if (curTest.size() < 1 || curTest.size() > 10) goodFlag = 0;
	for (int i = 0; i < (int)curTest.size(); i++)
	{
		if (curTest[i].n < 1 || curTest[i].n > MAX_N) goodFlag = 0;
		if (curTest[i].m < 1 || curTest[i].m > MAX_M) goodFlag = 0;
		for (int c = 0; c < curTest[i].m; c++)
		{
			if (curTest[i].edges[c][0] < 1 || curTest[i].edges[c][0] > curTest[i].n) goodFlag = 0;
			if (curTest[i].edges[c][1] < 1 || curTest[i].edges[c][1] > curTest[i].n) goodFlag = 0;
			if (curTest[i].edges[c][2] < 1 || curTest[i].edges[c][2] > 100) goodFlag = 0;
		}
	}
	if (!goodFlag)
	{
		fprintf(stderr, "Test %d is incorrect!\n", test);
		system("pause");
	}
	
	char fileName[32];
	sprintf(fileName, "Friday.%02d.in", test);
	FILE* out = fopen(fileName, "wt");
	
	fprintf(out, "%d\n", (int)curTest.size());
	for (int t = 0; t < (int)curTest.size(); t++)
	{
		fprintf(out, "%d %d\n", curTest[t].n, curTest[t].m);
		for (int i = 0; i < curTest[t].m; i++)
			fprintf(out, "%d %d %d\n", curTest[t].edges[i][0],
				curTest[t].edges[i][1], curTest[t].edges[i][2]);
		fprintf(out, "%s\n", curTest[t].isFriday ? "True" : "False");
	}
	fclose(out);
}


int main(void)
{
	srand(42);
	parseTests();

	int numTests = 20;
	sampleInput(); printTest(0);
	for (int test = 1; test <= numTests; test++)
	{
		curTest.clear();
		int testIdx = test > 10 ? test - 10 : test;
		if (testIdx == 1) randomTest(5);
		if (testIdx == 2) randomTest(10);
		if (testIdx == 3) randomTest(15);
		if (testIdx == 4) randomTest(20);
		if (testIdx == 5) randomTest(25);
		if (testIdx == 6) randomTest(30);
		if (testIdx == 7) randomTest(40);
		if (testIdx == 8) randomTest(45);
		if (testIdx == 9) largeNumberOfEdgesFromSingleNode();
		if (testIdx == 10) randomTest(MAX_N);
		
		if (test >= 1 && test <= 10)
			for (int i = 0; i < (int)curTest.size(); i++)
				curTest[i].isFriday = false;
		if (test >= 11 && test <= 20)
			for (int i = 0; i < (int)curTest.size(); i++)
				curTest[i].isFriday = true;
		printTest(test);
	}
	
	fprintf(stderr, "Finished generating tests...\n");
	system("pause");
	return 0;
}
