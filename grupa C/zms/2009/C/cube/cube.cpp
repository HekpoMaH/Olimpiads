#include<iostream>
#include<queue>
#include<string>
#include<assert.h>
using namespace std;

// UP		- движение към по-малък x
// DOWN	- движение към по-голям x
// LEFT	- движение към по-малък y
// RIGHT	- движение към по-голям y
enum DIR { UP=0, DOWN, LEFT, RIGHT };
DIR opposite[4] = { DOWN, UP, RIGHT, LEFT };

const int dx[] = {-1,+1,0,0};
const int dy[] = {0,0,-1,+1};

const int MAX_VALUE = 8*8*1002 + 1;

struct cube {
	int front;		// предната
	int back;		// задната
	int top;			// горната
	int right;		// дясната
	int bottom;		// долната 
	int left;		// лявата

	int move (DIR dir) {
		int x=bottom;
		
		//if (dir==1) {		//нагоре
		if (dir==UP) {			//нагоре
			bottom=back;
			back=top;
			top=front;
			front=x;
			return x;
		}

		//if (dir==3) {		//надолу
		if (dir==DOWN) {		//надолу
			bottom=front;
			front=top;
			top=back;
			back=x;
			return x;
		}

		//if (dir==2) {		//наляво
		if (dir==LEFT) {		//наляво
			bottom=left;
			left=top;
			top=right;
			right=x;
			return x;
		}

		//if (dir==4) {		//надясно
		if (dir==RIGHT) {		//надясно
			bottom=right;
			right=top;
			top=left;
			left=x;
			return x;
		}

		assert(0);
		return x;
    }

    void read () {
        cin >> front >> back >> top >> right >> bottom >> left;
    }
};

struct cell
{
    int x, y;

	 cell () {}
	 cell (int _x, int _y) : x(_x), y(_y) {}

    int operator ==(cell c) { return (x==c.x && y==c.y); }
};

int a[10][10], u[10][10];
cube starting_cube;
cell starting_cell,ending_cell;

void bfs(cell c)
{
	cell k, w;
	queue<cell> q;
	int i;

	u[c.x][c.y] = 1;
	q.push(c);

	while(!q.empty())
	{
		k = q.front();
		q.pop();
		
		if (k==ending_cell) break;
		
		for (i=0; i<4; i++) {
			w = cell(k.x+dx[i], k.y+dy[i]);//наляво
			if(a[w.x][w.y] && !u[w.x][w.y])
			{
				u[w.x][w.y] = u[k.x][k.y]+1;
				q.push(w);
			}
		}
	}
}
void read()
{
	string s;
	int i, j, n;

	for(i=1;i<=8;i++)
     for(j=1;j<=8;j++)
        a[i][j]=1;

	cin>>s;
	starting_cell = cell (7-(s[1]-'1')+1, s[0]-'a'+1);

	cin>>s;
	ending_cell = cell (7-(s[1]-'1')+1, s[0]-'a'+1);
	
	starting_cube.read();
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		a[7-(s[1]-'1')+1][s[0]-'a'+1]=0;
	}
}

void print_u()
{
	int i,j;
	for(i=1;i<=8;i++)
	{
		for(j=1;j<=8;j++)
			cout<<u[i][j]<<' ';
		cout<<endl;
	}
}

int restore (DIR curr_dir, cell curr_cell, cube &resulting_cube)
{
	int i, curr_sum, min_sum=MAX_VALUE;
	cube curr_cube;
	cell prev_cell;
	
	if (curr_cell==starting_cell) {
		min_sum = starting_cube.bottom;
		resulting_cube = starting_cube;
		resulting_cube.move (curr_dir);
	}
	else {
		for (i=0; i<4; i++) {
			prev_cell = cell(curr_cell.x+dx[ opposite[i] ], curr_cell.y+dy[ opposite[i] ]);

			if (u[prev_cell.x][prev_cell.y]+1==u[curr_cell.x][curr_cell.y])
			{
				curr_sum = restore((DIR)i,prev_cell,curr_cube) + curr_cube.bottom;
				if (curr_sum < min_sum)
				{
					min_sum = curr_sum;
					resulting_cube = curr_cube;
				}
			}
		}
	
		resulting_cube.move(curr_dir);
	}

	return min_sum;
}

int main()
{
	//freopen("cube.06.in", "r", stdin);

	cube resulting_cube;
	read();
	bfs(starting_cell);
	//print_u();

	cout << restore(UP,ending_cell,resulting_cube) << endl;
	
	return 0;
}
