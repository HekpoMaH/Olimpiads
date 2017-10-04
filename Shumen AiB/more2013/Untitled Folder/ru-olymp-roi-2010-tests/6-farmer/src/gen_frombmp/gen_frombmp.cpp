#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <map>
#include "bmp.h"

using namespace std;


int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cerr << "Usage: gen_frombmp <bmp_file>";
		return 1;
	}
	bmp_header hdr;
	vector<vector<int> > data;
	bmpRead(argv[1], &hdr, data);
	printf("%d %d\n", data.size(), data[0].size());
	int i, j;
	for (i = 0; i < data.size(); i++)
	{
		for (j = 0; j < data[i].size(); j++)
		{
			int avg = data[i][j] % 256 + (data[i][j] >> 8) % 256 + (data[i][j] >> 16) % 256;
			avg /= 3;
			if (avg <= 240) printf("1");
			else printf("0");
		}
		printf("\n");
	}
	/*for (i = 0; i < data.size(); i++)
	{
		for (j = 0; j < data[i].size(); j++)
		{
			cerr << "(" << data[i][j] % 256 << "," << (data[i][j] >> 8) % 256 << "," << (data[i][j] >> 16) % 256 << ") ";
		}
		cerr << "\n";
	}*/
	return 0;
}