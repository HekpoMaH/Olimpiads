//The following code is based on the paper "Dancing Links" by D. E. Knuth.
//See http://www-cs-faculty.stanford.edu/~uno/papers/dancing-color.ps.gz
#ifndef DLX_H
#define DLX_H
#include <cstring>
#include <climits>
struct data_object //A module in the sparse matrix data structure.
{
	data_object* L;                //Link to next object left.
	data_object* R;                //         "          right.
	data_object* U;                //         "          up.
	data_object* D;                //         "          down.
	data_object* C;                //Link to column header.
	int x;                         //In a column header: number of ones
                                       //in the column. Otherwise: row index.
	void cover()                   //Covers a column.
	{
		data_object* i=D;
		data_object* j;
		R->L=L;
		L->R=R;
		while (i!=this)
		{
			j=i->R;
			while (j!=i)
			{
				j->D->U=j->U;
				j->U->D=j->D;
				j->C->x--;
				j=j->R;
			}
			i=i->D;
		}
	}
	void uncover()                 //Uncovers a column.
	{
		data_object* i=U;
		data_object* j;
		while (i!=this)
		{
			j=i->L;
			while (j!=i)
			{
				j->C->x++;
				j->D->U=j;
				j->U->D=j;
				j=j->L;
			}
			i=i->U;
		}
		R->L=this;
		L->R=this;
	}
};
//Standard S-heuristic suggested in Knuth's paper: pick the column with the
//fewest ones. Takes the root of the sparse matrix structure as an argument;
//returns a pointer to the column header with the fewest ones.
data_object* DLX_Knuth_S_heuristic(data_object* root)
{
	data_object* P=root->R;
	data_object* res;
	int best=INT_MAX/2;
	res = NULL;
	while (P!=root)
	{
		if (P->x<best)
		{
			best=P->x;
			res=P;
		}
		P=P->R;
	}
	return res;
}
template <typename Func1,typename Func2>
/*
Actual recursive function implementing Knuth's Dancing Links method.
h is the root of the sparse matrix structure.
O is the stack that will contain a list of rows used.
*/
void DLX_search(data_object* h,int k,int* O,Func1 send_row,
		Func2 choose_column)
{
	int i;
	data_object *r,*c,*j;
	if (h->R==h) //done - solution found
	{
		//send rows used in solution back...
		for (i=0; i<k; i++)
			send_row(O[i]);
		//-1 signifies end of solution
		send_row(-1);
		return;
	}
	//otherwise
	c=choose_column(h); //choose a column to cover
	c->cover();         //cover it
	r=c->D;
	while (r!=c)
	{
		O[k]=r->x;
		j=r->R;
		while (j!=r)
		{
			j->C->cover();
			j=j->R;
		}
		DLX_search(h,k+1,O,send_row,choose_column);
		//set r <- O[k], and c<- C[r], this is unnecessary
		j=r->L;
		while (j!=r)
		{
			j->C->uncover();
			j=j->L;
		}
		r=r->D;
	}
	c->uncover();
}
template <typename random_access_iterator,typename Func1,typename Func2>
/*
Meta-implementation of Knuth's Dancing Links method for finding solutions to
the exact cover problem.

PARAMETERS:
int rows: Number of rows in the matrix.
int cols: Number of columns in the matrix.
random_access_iterator buf: A random access iterator to ints (either 0 or
1), the entries of the matrix, in row major order.
Func1 send_row: A function object with return type void which takes as a
parameter the index of a row in a solution to the problem. (e.g. store it in
a buffer or print it out) -1 signifies the end of a solution.
Func2 choose_column: A deterministic function object taking as a parameter a
data_object* (the root) and returning a data_object* (the header of the
column to choose.)
*/
void DLX_dancing_links(int rows,int cols,random_access_iterator buf,
			Func1 send_row,Func2 choose_column)
{
	//step 1: construct the linked-list structure.
	//We can do this by iterating through the rows and columns. Time is
	//linear in the number of entries (optimal).
	//Space used is linear in the number of columns + the number of rows
	// + the number of ones.
	int i,j;
	data_object* root=new data_object; //root
	data_object* P=root;               //left-right walker
	data_object* Q;                    //top-down walker
	//array of pointers to column headers
	data_object** walkers=new data_object*[cols];
	//auxiliary stack for recursion
	int* st=new int[rows];
	for (i=0; i<cols; i++)
	{
		//create a column header and L/R links
		(P->R=new data_object)->L=P;
		//store a pointer to the column header
		walkers[i]=Q=P=P->R;
		P->x=0; //reset popcount
		for (j=0; j<rows; j++)
			if (buf[i+cols*j]) //a 1 in the current location?
			{
				//create a data object and U/D links
				(Q->D=new data_object)->U=Q;
				Q=Q->D;  //advance pointer
				Q->C=P;  //link to the column header
				P->x++;  //increment popcount for this column
				Q->x=j;  //note the row number of this entry
			}
		Q->D=P; //complete the column
		P->U=Q;
	}
	P->R=root; //complete the column list
	root->L=P;
	//eliminate empty columns
	P=root;
	for (i=0; i<cols; i++)
	{
		P=P->R;
		if (!P->x)
		{
			P->L->R=P->R;
			P->R->L=P->L;
		}
	}
	//now construct the L/R links for the data objects.
	P=new data_object;
	for (i=0; i<rows; i++)
	{
		Q=P;
		for (j=0; j<cols; j++)
			if (buf[j+cols*i]) //a one
			{
				//in _this_ row...
				walkers[j]=walkers[j]->D;
				//create L/R links
				(Q->R=walkers[j])->L=Q;
				//advance pointer
				Q=Q->R;
			}
		if (Q==P) continue;
		Q->R=P->R;       //link it to the first one in this row.
		P->R->L=Q;       //link the first one to the last one.
	}
	delete P;                //P is no longer needed
	delete walkers;          //walkers are no longer needed
	//step 2: recursive algorithm
	DLX_search(root,0,st,send_row,choose_column);
	delete st;
	P=root->R;
	while (P!=root)          //deallocate sparse matrix structure
	{
		Q=P->D;
		while (Q!=P)
		{
			Q=Q->D;
			delete Q->U;
		}
		P=P->R;
		delete P->L;
	}
	delete root;
}

//If no heuristic is specified, Knuth's S heuristic is used - select the
//column with the fewest ones to minimize the breadth of the search tree.
template <typename random_access_iterator,typename Func1>
void DLX_dancing_links(int rows,int cols,random_access_iterator buf,Func1 send_row)
{
	DLX_dancing_links(rows,cols,buf,send_row,DLX_Knuth_S_heuristic);
}

#endif
