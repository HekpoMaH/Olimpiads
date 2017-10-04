/*
Roads Testgen
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX 128

int n, m;
char board[MAX][MAX];

// 4 by 5
char sample[8][8] = {
	".....",
	"E##..",
	".#..X",
	"....#"
};

// 4 by 5
char handTest1[8][8] = {
	".....",
	"X##..",
	".#..E",
	"....#"
};

// 8 by 16
char handTest2[16][32] = {
	".........#.....#",
	".#........#..X..",
	"....#..#........",
	"....#.#..##.....",
	"..#.......#.....",
	"#E.#..........#.",
	"........##......",
	"#..............."
};

// 7 by 39
char handTest3[8][64] = {
	".......................................",
	".#####...###..####...####...##..######.",
	".##.....##....##.##..##.X#..##....##...",
	".###E....##...####...####...##....##...",
	".##.......##..##.....###....##....##...",
	".#####..###...##.....##.#...##....##...",
	"......................................."
};

// 12 by 100
char handTest4[16][128] = {
	"....................................................................................................",
	"......####....##........###..###.......###..##......##..##........###......##.....###.....#X#.......",
	".....######...##.......####..####.....####..##......##..##.......####.......#....####...#######.....",
	"....#.....##..##......##.##..##.##...##.##..##......##..##......##.##......#....#..##..#......##....",
	"..........##..##.....##..##..##..##.##..##..##......##..##.....##..##..........#...##........##.....",
	"........###...##....##...##..##...###...##..##########..##....##...##..............##.......##......",
	"........###...##...##....##..##....#....##..##########..##...##....##..............##......##.......",
	"..........##..##..##.....##..##.........##..##......##..##..##.....##..............##.....##........",
	"....#.....##..##.##......##..##.........##..##......##..##.##......##..............##....##.........",
	".....######...####.......##..##.........##..##......##..####.......##..............##...##....##....",
	"......E###....###........##..##.........##..##......##..###........##..............##...########....",
	"...................................................................................................."
};

// 8 by 5
char handTest5[16][8] = {
	".....",
	".#E#.",
	"..#..",
	".#.#.",
	".#.#.",
	"..#..",
	".#X#.",
	"....."
};

// 8 by 8
char handTest6[16][16] = {
	".......E",
	"........",
	"........",
	"........",
	"........",
	"........",
	"........",
	"X......."
};

// 8 by 10
char handTest7[16][16] = {
	"..#...#.E.",
	"....#...#.",
	"..#...#...",
	"....#...#.",
	"..#...#...",
	"....#...#.",
	"..#...#...",
	".X..#...#."
};

// 7 by 20
char handTest8[8][32] = {
	"....................",
	"....................",
	".............#......",
	".....X...##...E.....",
	"......#.............",
	"....................",
	"...................."
};

// 9 by 50
char handTest9[16][64] = {
	"..................................................",
	".##.....##..#####.....######.##....##.##.########.",
	".###....##.##...##....##......##..##..##....##....",
	".####...##.##...##....##.......####...##....##....",
	".##.##..##.##.E.##....####......##....##....##....",
	".##..##.##.##...##....##.......####...##....##....",
	".##...####.##...##....##......##..##........##....",
	".##....###..#####.....######.##....##.##....##..X.",
	".................................................."
};

// 1 by 2
char handTest10[4][4] = {
	"EX"
};

// 5 by 7
char handTest11[8][8] = {
	".......",
	".#####.",
	"..E#X..",
	".#####.",
	"......."
};

// 4 by 6
char handTest12[8][8] = {
	"E#....",
	"...#..",
	"###...",
	"#X...."
};


void sampleInput()
{
	n = 4; m = 5;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = sample[i][c];
}

void smallTest1()
{
	n = 4; m = 5;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = handTest1[i][c];
}

void smallTest2()
{
	n = 8; m = 16;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = handTest2[i][c];
}

void smallTest3()
{
	n = 7; m = 39;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = handTest3[i][c];
}

void smallTest4()
{
	n = 12; m = 100;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = handTest4[i][c];
}

void smallTest5()
{
	n = 8; m = 5;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = handTest5[i][c];
}

void smallTest6()
{
	n = 8; m = 8;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = handTest6[i][c];
}

void smallTest7()
{
	n = 8; m = 10;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = handTest7[i][c];
}

void smallTest8()
{
	n = 7; m = 20;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = handTest8[i][c];
}

void smallTest9()
{
	n = 9; m = 50;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = handTest9[i][c];
}

void smallTest10()
{
	n = 1; m = 2;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = handTest10[i][c];
}

void smallTest11()
{
	n = 5; m = 7;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = handTest11[i][c];
}

void smallTest12()
{
	n = 4; m = 6;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = handTest12[i][c];
}

void randomTest(int n_, int m_)
{
	n = n_; m = m_;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = '.';
	double density = 0.1 + 0.2 * rand() / RAND_MAX;
	int numObstacles = (int)(density * n * m);
	for (int obstacle = 0; obstacle < numObstacles; obstacle++)
		board[rand() % n][rand() % m] = '#';

	// This might fail
	board[rand() % 5][rand() % m] = 'E';
	board[n - rand() % 5 - 1][rand() % m] = 'X';
}

void empty(int n_, int m_)
{
	n = n_; m = m_;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = '.';
	board[n - 1][0] = 'X';
	board[0][m - 1] = 'E';
}

void grid(int n_, int m_)
{
	n = n_; m = m_;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = '.';
	for (int i = 0; i < n; i += 2)
		for (int c = 0; c < m; c += 2)
			board[i][c] = '#';
	board[1][2] = 'X';
	board[n - 2][m - 3] = 'E';
}

/*
E........
########.
.........
.########
.........
########.
X........
*/
void snake(int n_, int m_)
{
	n = n_; m = m_;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = '.';
	for (int i = 1; i < n; i += 4)
		for (int c = 0; c < m - 1; c++)
			board[i][c] = '#';
	
	for (int i = 3; i < n; i += 4)
		for (int c = 1; c < m; c++)
			board[i][c] = '#';
	
	board[0][0] = 'E';
	for (int i = 0; i < m; i++)
		board[n - 1][i] = '.';
	if (board[n - 2][0] == '#')
		board[n - 1][0] = 'X';
	else
		board[n - 1][m - 1] = 'X';
}

/*
E...........
###########.
..........#.
.########.#.
.#......#.#.
.#.####.#.#.
.#.#....#.#.
.#.#X...#.#.
.#.######.#.
.#........#.
.##########.
............
*/

void spiral(int n_, int m_)
{
	n = n_; m = m_;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			board[i][c] = '.';

	int row = 1, col = 1, cdir = 0, prnt = n - 2, rem = 3;
	int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	while(prnt > 12)
	{
		for (int i = 0; i < rem; i++)
		{
			for (int c = 0; c < prnt; c++)
			{
				board[row][col] = '#';
				row += dir[cdir][0];
				col += dir[cdir][1];
			}
			row -= dir[cdir][0];
			col -= dir[cdir][1];
			cdir = (cdir + 1) % 4;
			
		}
		rem = 2; prnt -= 2;
	}
	board[0][0] = 'E';
	board[1][0] = '#';
	row = n / 2; col = m / 2;
	while (board[row - 2][col] != '#') row--;
	while (board[row][col + 2] != '#') col++;
	board[n / 2 - 1][m / 2 - 1] = '#';
	board[n / 2 + 1][m / 2 + 1] = '#';
	board[row][col] = 'X';
}

void printTest(int testNum)
{
	int numEllys = 0, numExits = 0;
	for (int i = 0; i < n; i++)
		for (int c = 0; c < m; c++)
			if (board[i][c] == 'E') numEllys++;
			else if (board[i][c] == 'X') numExits++;

	if (numEllys != 1)
	{
		fprintf(stderr, "Test %d is invalid. Number of Ellys is %d.\n", testNum, numEllys);
		system("pause");
	}
	if (numExits != 1)
	{
		fprintf(stderr, "Test %d is invalid. Number of Exits is %d.\n", testNum, numExits);
		system("pause");
	}
	
	char outFile[32];
	sprintf(outFile, "Roads.%02d.in", testNum);
	FILE* out = fopen(outFile, "wt");
	fprintf(out, "%d %d\n", n, m);
	for (int i = 0; i < n; i++)
		fprintf(out, "%s\n", board[i]);
	fclose(out);
}

int main(void)
{
	srand(42);
	int numTests = 20;
	for (int test = 0; test <= numTests; test++)
	{
		memset(board, 0, sizeof(board));

		if (test == 0) sampleInput();
		else if (test == 1) smallTest1(); // len is 7, size is 5
		else if (test == 2) smallTest2(); // len is 18, size is 16
		else if (test == 3) smallTest3(); // len is INF, size is 39
		else if (test == 4) smallTest4(); // len is 98, size is 100
		else if (test == 5) smallTest5(); // len is 13, size is 8
		else if (test == 6) smallTest6(); // len is 14, size is 8
		else if (test == 7) smallTest7(); // len is 14, size is 10
		else if (test == 8) smallTest8(); // len is 11, size is 20
		else if (test == 9) smallTest9(); // len is INF, size is 50
		else if (test == 10) smallTest10(); // len is 1, size is 2
		else if (test == 11) smallTest11(); // len is 14, size is 7
		else if (test == 12) smallTest12(); // len is 12, size is 6
		else if (test == 13) snake(50, 50); // len is 1225, size is 50
		else if (test == 14) randomTest(42, 42); // len is 50, size is 42
		else if (test == 15) randomTest(50, 50); // len is 55, size is 50
		else if (test == 16) randomTest(71, 93); // len is 82, size is 93
		else if (test == 17) empty(100, 100); // No obstacles, len is 198, size is 100
		else if (test == 18) grid(100, 100); // Obstacles in a grid, len is 192, size is 100
		else if (test == 19) snake(100, 100); // Maximal path len in a snake, len is 5049, size is 100
		else if (test == 20) spiral(100, 100); // Maximal path len in a spiral, len is 5025, size is 100
		
		printTest(test);
	}
	fprintf(stderr, "Finished generating all test cases!\n");
	system("pause");
	return 0;
}
