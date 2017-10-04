
# include <cstdio>
#include<iostream>
# include <vector>

using namespace std;

struct state
{
	int r[10];
	int worl;
	int code;
	state ()
	{
		int i;
		for (i = 0; i < 9; i ++)
			r[i] = 0;
		worl = -1;
		code = -1;
	}
	void ccode ()
	{
		int i;
		code = 0;
		for (i = 0; i < 9; i ++)
			code = code * 10 + r[i];	
	}
};

int n, m;
int x[10];

vector <bool> used (1000000000, 0);
vector <bool> ma (1000000000, 0);

state start;

vector <pair <int, int> > ans;

bool win (state curr)
{
	int i, j, p;
	if (curr.code == -1)
		curr.ccode ();
	
	/**	
	printf ("%d ", curr.code);
	for (i = 0; i < 9; i ++)
		printf ("%d ", curr.r[i]);
	printf ("\n\n");
	**/
	
	if (used[curr.code])
		return ma[curr.code];
		
	state next;
	
	for (i = 0; i < 9; i ++)
		next.r[i] = curr.r[i];
	
	for (i = 0; i < n; i ++)
		for (j = 1; j <= curr.r[i]; j ++)
		{
			for (p = i; p < n; p ++)
				next.r[p] = min (next.r[p], j - 1);
			if (!win (next))
			{
				used[curr.code] = 1;
				ma[curr.code] = 1;
                                //puts(" 1 ");
				return true;
			}
			for (p = i; p < n; p ++)
				next.r[p] = curr.r[p];
		}
	
	used[curr.code] = 1;
	ma[curr.code] = 0;
        //puts(" -1 ");
	return false;
}

int main ()
{
	int i, j, p, worl = 0;
	state next;
	scanf ("%d%d", &n, &m);
	for (i = 0; i < n; i ++)
	{
		scanf ("%d", &x[i]);
		start.r[i] = x[i];
	}
	
	for (i = 0; i < 9; i ++)
		next.r[i] = start.r[i];
	
	used[0] = 1;
	ma[0] = 1;
	
	used[1000000000] = 1;
	ma[1000000000] = 0;

	
	worl = win (start);
	
      //puts("\n");	
	if (worl)
		for (i = 0; i < n; i ++)
			for (j = 1; j <= start.r[i]; j ++)
			{
				for (p = i; p < n; p ++)
					next.r[p] = min (next.r[p], j - 1);
				next.ccode ();
                                cout<<next.code<<"\n";
				if (!used[next.code])
					worl = win (next);
				if (!ma[next.code]){
					ans.push_back (make_pair (i + 1, j));
                                }
		
				for (p = i; p < n; p ++)
					next.r[p] = start.r[p];
			}
			
	printf ("%d\n", (int) ans.size ());
	
	for (i = 0; i < ans.size (); i ++)
		printf ("%d %d\n", ans[i].first, ans[i].second);

	return 0;
}
