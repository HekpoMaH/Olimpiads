#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

unsigned rnd = 42;
int randInt()
{
	rnd = rnd * 1103515245 + 12345;
	return ((rnd & ((1 << 30) - 1)) >> 3);
}

string toString(long long num)
{
	if (num == 0) return "0";
	string ret;
	while (num) {ret.push_back(num % 10 + 48); num /= 10;}
	reverse(ret.begin(), ret.end());
	return ret;
}

int curTest = 0;
void smallTest()
{
	char testName[32];
	sprintf(testName, "Unique.%02d.in", ++curTest);
	FILE *out = fopen(testName, "wt");
	
	int a, b;
	if (curTest == 1)
		fprintf(out, "1 100\n");
	else if (curTest == 3)
		fprintf(out, "1337 12345\n");
	else if (curTest == 5)
		fprintf(out, "42 42\n");
	else if (curTest == 7)
		fprintf(out, "1337 1337\n");
	else if (curTest == 9)
		fprintf(out, "12345 54321\n");
	else if (curTest == 11)
		fprintf(out, "1 1000000000\n");
	else if (curTest == 13)
		fprintf(out, "11 111111111\n");
	else if (curTest == 15)
		fprintf(out, "41151324 41196923\n");
	else if (curTest == 17)
		fprintf(out, "13 1313131313\n");
	else if (curTest == 19)
		fprintf(out, "1234567890 9876543210\n");
	else
	{
		long long a, b;
		while (1)
		{
			a = ((long long)rand() * (long long)randInt()) % 10000000000LL + 5;
			b = ((long long)rand() * (long long)randInt()) % 10000000000LL + 5;
			if (a > b) swap(a, b);
			if (b - a > 10000000) break;
		}
		fprintf(out, "%s %s\n", toString(a).c_str(), toString(b).c_str());
	}	
	fclose(out);
}


void largeTest()
{
	char testName[32];
	sprintf(testName, "Unique.%02d.in", ++curTest);
	FILE *out = fopen(testName, "wt");
	
	if (curTest == 2)
		fprintf(out, "512 617\n");
	else if (curTest == 4)
		fprintf(out, "1300 1800\n");
	else if (curTest == 6)
		fprintf(out, "239483498534985 239483498564987\n");
	else if (curTest == 8)
		fprintf(out, "4398545986023480923853406984369 4398545986023480923853406995369\n");
	else if (curTest == 10)
		fprintf(out, "43985340583409853409852093843094854309685346 43985340583409853409852093843094854309685346\n");
	else if (curTest == 12)
		fprintf(out, "13 10000013\n");
	else if (curTest == 14)
		fprintf(out, "13 3142536475\n");
	else if (curTest == 16)
		fprintf(out, "100000000000000000 100000000000000000000000000000000000000000000000000000000000000000000000000\n");
	else if (curTest == 18)
		fprintf(out, "1 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n");
	else if (curTest == 20)
		fprintf(out, "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n");
	else
	{
		char num1[128], num2[128];
		int len1 = rand() % 99 + 1;
		int len2 = rand() % 100 + 1;
		len2 = max(len2, len1 + 1);

		num1[0] = rand() % 9 + 49;
		for (int i = 1; i < len1; i++)
			num1[i] = rand() % 10 + 48;

		num2[0] = rand() % 9 + 49;
		for (int i = 1; i < len2; i++)
			num2[i] = rand() % 10 + 48;

		num1[len1] = 0; num2[len2] = 0;
		fprintf(out, "%s %s\n", num1, num2);
	}	
	fclose(out);
}

int main(void)
{
	int numTests = 20;
	for (int curTest = 1; curTest <= numTests; curTest++)
	{
		smallTest();
		largeTest();
	}
	return 0;
}
