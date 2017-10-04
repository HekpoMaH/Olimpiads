#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Passenger
{
public:
	int l, r, t;
};

int m, k;
vector<Passenger> p;

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		fprintf(stderr, "Usage: merge FILE1 [FILE2, ...[ FILEN ] ]\n");
		return 1;
	}
	p.clear();
	m = k = 0;
	int t, i;
	for (t = 1; t < argc; t++)
	{
		int cn, cm, ck;
		FILE *fin = fopen(argv[t], "rt");
		if (!fin)
		{
			fprintf(stderr, "Could not open file %s\n", argv[t]);
			return 1;
		}
		fscanf(fin, "%d%d%d", &cn, &cm, &ck);
		for (i = 0; i < cn; i++)
		{
			Passenger a;
			fscanf(fin, "%d%d%d", &a.l, &a.r, &a.t);
			a.l += m;
			a.r += m;
			p.push_back(a);
		}
		m += cm;
		if (k != 0 && ck != k) 
		{
			fprintf(stderr, "Different k - unable to proceed\n");
			return 1;
		}
		k = ck;
	}
	printf("%d %d %d\n", (int)p.size(), m, k);
	for (i = 0; i < (int)p.size(); i++)
	{
		printf("%d %d %d\n", p[i].l, p[i].r, p[i].t);
	}
	return 0;
}
