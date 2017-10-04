/*
ID: espr1t
LANG: C++
TASK: Browse
KEYWORDS: Testgen
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define MAX 1024

struct Point
{
    int x, y;
    Point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
};

int n, m, k;
Point a[MAX], b[MAX];

void sampleInput()
{
    n = 5; m = 3; k = 2;
    a[0] = Point(2, 13);
    a[1] = Point(9, 6);
    a[2] = Point(4, 8);
    a[3] = Point(13, 7);
    a[4] = Point(11, 3);
    b[0] = Point(2, 11);
    b[1] = Point(10, 6);
    b[2] = Point(4, 12);
}

void randomTest(int n_, int m_, int k_)
{
    n = n_; m = m_; k = k_;
    for (int i = 0; i < n; i++)
        a[i] = Point(rand() % 2001 - 1000, rand() % 2001 - 1000);
    for (int i = 0; i < m; i++)
        b[i] = Point(rand() % 2001 - 1000, rand() % 2001 - 1000);
}

void allAtTheSamePoint(int n_, int m_, int k_)
{
    n = n_; m = m_; k = k_;
    for (int i = 0; i < n; i++)
        a[i] = Point(42, 42);
    for (int i = 0; i < m; i++)
        b[i] = Point(42, 42);
}

void atDifferentSides(int n_, int m_, int k_)
{
    n = n_; m = m_; k = k_;
    for (int i = 0; i < n; i++)
        a[i] = Point(-1000, 0 + i);
    for (int i = 0; i < m; i++)
        b[i] = Point(+1000, 1 + i);
    std::random_shuffle(a, a + n);
    std::random_shuffle(b, b + n);
}

void closestIsBad1(int n_, int m_, int k_)
{
	n = n_; m = m_; k = k_;
	for (int i = 0; i < n; i++)
		a[i] = Point(i, 0);
	for (int i = 0; i < m; i++)
		b[i] = Point(i, i);
}

void closestIsBad2(int n_, int m_, int k_)
{
	n = n_; m = m_; k = k_;
	for (int i = 0; i < n; i++)
		a[i] = Point(0, -i);
	for (int i = 0; i < m; i++)
		b[i] = Point(0, +i);
}

void closestIsBad3(int n_, int m_, int k_)
{
	n = n_; m = m_; k = k_;
	for (int i = 0; i < n; i++)
		a[i] = Point(i, i);
	for (int i = 0; i < m; i++)
		b[i] = Point(i, 999 - i);
}


void printTest(int testNum)
{
    char fileName[32];
    sprintf(fileName, "Browse.%02d.in", testNum);
    FILE* out = fopen(fileName, "wt");
    fprintf(out, "%d %d %d\n", n, m, k);
    for (int i = 0; i < n; i++)
        fprintf(out, "%d %d\n", a[i].x, a[i].y);
    for (int i = 0; i < m; i++)
        fprintf(out, "%d %d\n", b[i].x, b[i].y);
    fclose(out);
}

int main(void)
{
    int numTests = 20;
    for (int test = 0; test <= numTests; test++)
    {
        if (test == 0) sampleInput();
        if (test == 1) randomTest(7, 3, 3);
        if (test == 2) randomTest(10, 4, 3);
        if (test == 3) randomTest(11, 6, 2);
        if (test == 4) randomTest(12, 12, 1);
        if (test == 5) randomTest(13, 2, 8);
        if (test == 6) randomTest(13, 1, 13);
        if (test == 7) randomTest(14, 5, 5);
        if (test == 8) randomTest(15, 8, 3);
        if (test == 9) randomTest(15, 15, 3);
        if (test == 10) randomTest(15, 15, 15);
        if (test == 11) randomTest(100, 60, 2);
        if (test == 12) randomTest(200, 300, 1);
        if (test == 13) randomTest(300, 300, 1);
        if (test == 14) randomTest(500, 10, 53);
        if (test == 15) randomTest(500, 50, 50);
        if (test == 16) allAtTheSamePoint(500, 500, 1);
        if (test == 17) atDifferentSides(500, 500, 1);
        if (test == 18) closestIsBad1(500, 500, 1);
        if (test == 19) closestIsBad2(500, 500, 1);
        if (test == 20) closestIsBad3(500, 500, 1);

        printTest(test);
    }
    fprintf(stderr, "Finished generating test cases.\n");
    system("pause");
    return 0;
}
