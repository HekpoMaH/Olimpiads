/*========================================================
Here's my implementation of Knuth's "Algorithm X with Dancing Links", or DLX for short, for solving the exact cover problem.
This is in the file dlx.h.
The file dlx_driver.cpp is, as its name suggests, a driver for the header, reducing Sudoku to exact cover.
To use the Sudoku solver, simply input 81 cells to standard input.
Digits 1..9 represent givens (as one would expect). The digit zero and the period represent blank cells.
All other characters are ignored. Thus, input is accepted in several different formats.
In most cases you can simply copy-and-paste into the console what you find online.
(Spaces are ignored, not treated as placeholders. This means if spaces are used as placeholders, this won't work properly.
On the other hand if I treat spaces as placeholders, leading and trailing spaces cause problems, which IMHO is worse.)
Solutions are printed to standard output as 9x9 grids of digits - all possible solutions are printed, as they are generated
one by one as the recursive algorithm proceeds. Each solution is followed by a blank line.
If no solutions are found, nothing will be printed.
Also, before I start getting attacked over my misuse of templates, choice of language, poor commenting, and overall sloppiness,
remember that I'm primarily a computer science enthusiast, not a software engineer.
==============================================*/
#include <iostream>
#include <stdio.h>
#include "dlx.h"

using namespace std;
#define NINE 9
#define TREE 3

#define block(r,c) (TREE*((r)/TREE)+((c)/TREE)) //pmp
int cnt=0;
int grid[NINE][NINE];
int c729=NINE*NINE*NINE, c324=NINE*NINE*4, c243=NINE*NINE*TREE;

void f(int x)
{
	int i;
	int c;
	int r;
	if (x+1)
	{
		i=x%NINE; x/=NINE;
		c=x%NINE; r=x/NINE;
		grid[r][c]=i+1;
	}
	else
	{
	    for (r=0; r<NINE; r++,putchar('\n'))
			for (c=0; c<NINE; c++)
				// putchar(grid[r][c]+'0');
				printf("%d ",grid[r][c]);
        printf("=================\n");
	}
}
int matrix[NINE*NINE*NINE][NINE*NINE*4];
void cover_col(int col)
{
	for (int row=0; row<c729; row++)
		if (matrix[row][col])
		{
			matrix[row][col]=0;
			memset(matrix[row],0,sizeof(matrix[row]));
		}
}
void cover_row(int row)
{
	for (int col=0; col<c324; col++)
		if (matrix[row][col])
		{
			matrix[row][col]=0;
			cover_col(col);
		}
}

int main()
   {
	int row,r,c,i;

	char ch;
	int inp;
	for(row=0,r=0; r<NINE; r++)
       for(c=0; c<NINE; c++)
		  for(i=0; i<NINE; i++,row++)
			 {
				//uniqueness constraint
				matrix[row][r+NINE*c]=1;
				//row constraint
				matrix[row][NINE*NINE+i+NINE*r]=1;
				//column constraint
				matrix[row][NINE*NINE*2+i+NINE*c]=1;
				//block constraint
				matrix[row][c243+i+NINE*block(r,c)]=1;
			 }
	for(r=0; r<NINE; r++)
       {
		for(c=0; c<NINE; c++)
		   {
		    scanf("%c",&ch);
			if((ch>='1'&&ch<='9')||ch=='A'||ch=='B'||ch=='C'||ch=='D'||ch=='E'||ch=='F'||ch=='G') //known value
			  {
			   if (ch>='1'&&ch<='9')inp = ch -'0';
			   else inp = 10 + ch-'A';
			   cover_row(NINE*NINE*r+NINE*c+inp-1);
               grid[r][c]=inp;//ch-'0';
               printf("%d ",grid[r][c]);
			  }
			else if(ch != '0')//if (ch!='.'&&ch!='0') //placeholder
			       {
				    c--;
				    continue;
			       }
                 else printf("%c ", ch);

           }
	putchar('\n');
	   }
	printf("=================\n");
	/* Control print */
	int u9, v9;
	for(u9=0; u9<729; u9++)
    {
        for(v9=0; v9<324;v9++)printf("%d ",matrix[u9][v9]);
        printf("\n",matrix[u9][v9]);
    }

	/*================*/
	DLX_dancing_links(c729,c324,(int *)&matrix,f);
	return 0;
}

