/* zerodlx.cpp Copyright 2008 Jim Schirle */
#include
#include
class Zerodlx
{
private: class column;
class node
 { public: node *l, *r, *d, *u; column *c; int row; };
  class column : public node
  { public: int size; column *L, *R; bool covered; };
  int BOX, UNIT, GRID, solnCount, maxSolutions;
   std::vector solution; column* head;
   std::vector cols;
   std::vector< std::vector > matrix;
   public: Zerodlx(int sz = 3, int maxSolns = 1) : BOX(sz),
   UNIT(BOX*BOX), GRID(UNIT*UNIT), maxSolutions(maxSolns), solution(GRID, 0), cols(GRID*4+1, column()), matrix(GRID*UNIT, std::vector(4, node()))
   { head = &(cols[GRID*4]);
   int g4 = GRID*4+1;
   for (int i = 0; i < g4; i++)
   { // construct the columns
   cols[i].L = &(cols[(i+g4-1)%g4]);
   cols[i].R = &(cols[(i+1)%g4]);
   cols[i].u = &(cols[i]);
   cols[i].d = &(cols[i]);
   cols[i].size = 0;
   cols[i].covered = false;
   }
   for (int i = 0; i < GRID*UNIT; i++)
   // construct the rows

   for (int j = 0; j < 4; j++)
   {
    matrix[i][j].r = &(matrix[i][(j+1)%4]);
    matrix[i][j].l = &(matrix[i][(j+3)%4]);
    matrix[i][j].row = i;
    int colNum = GRID*j;
    if (j == 0)
    // row-col
    colNum += i/GRID*UNIT+i%GRID/UNIT;
    else if (j == 1)
    // row-value
    colNum += i/GRID*UNIT+i%UNIT;
    else if (j == 2)
    // col-value
    colNum += i%GRID/UNIT*UNIT+i%UNIT;
    else if (j == 3)
    // box-value
    colNum += (i/GRID/BOX*BOX+i%GRID/UNIT/BOX)*UNIT+i%UNIT;
    matrix[i][j].d = matrix[i][j].c = &(cols[colNum]);
     matrix[i][j].u = cols[colNum].u;
     cols[colNum].u->d = cols[colNum].u = &(matrix[i][j]);
     cols[colNum].size++; } }
     // public method to solve a given puzzle.
     // returns number of solutions and fills in the *puzzle array with solution
      int solve(std::vector& puzzle)
      {
      if (puzzle.size() != GRID) return -1;
       int k = 0;
       solnCount = 0;
       bool noSoln = false;
       for (int i = 0;i < GRID; i++)
        if (puzzle[i])
        {
        int row = i * UNIT + puzzle[i] - 1;
        if (matrix[row][0].c->covered || matrix[row][1].c->covered || matrix[row][2].c->covered || matrix[row][3].c->covered)

        { noSoln = true; break; } for (int j = 0; j < 4; j++) cover(matrix[row][j].c); solution[k++] = row; } if (!noSoln) search(k); if (solnCount > 0) for (int i = 0; i < GRID; i++) { int pos = solution[i] / UNIT; puzzle[pos] = solution[i] % UNIT + 1; } for (int i = k - 1; i >= 0; i--) for (int j = 3; j >= 0; j--) uncover(matrix[solution[i]][j].c); return solnCount; } private: // DLX recursive search(k) function - does the work void search(int k) { if (head->R == head) { solnCount++; return; } column *c, *min = head->R; for (c = head->R; c != head; c = c->R) { if (c->size < min->size) min = c; if (min->size == 0) return; } cover(min); for (node *r = min->d; r != min && solnCount < maxSolutions; r = r->d) { if (solnCount == 0) solution[k] = r->row; for (node *j = r->r; j != r; j = j->r) cover(j->c); search(k + 1); for (node *j = r->l; j != r; j = j->l) uncover(j->c); } uncover(min); } // covers a given column void cover(column *c) { c->covered = true; c->R->L = c->L; c->L->R = c->R; for (node *i = c->d; i != c; i = i->d) for (node *j = i->r; j != i; j = j->r) { j->d->u = j->u; j->u->d = j->d; j->c->size--; } } // uncover a given column void uncover(column *c) { c->covered = false; for (node *i = c->u; i != c; i = i->u) for (node *j = i->l; j != i; j = j->l) { j->c->size++; j->u->d = j; j->d->u = j; } c->L->R = c; c->R->L = c; } }; using namespace std; int main(int argc, char **argv) { int p[] = {0,0,7,0,0,0,0,0,0, 4,3,0,0,1,5,0,8,0, 0,6,0,0,0,0,0,0,0, 0,0,1,0,0,8,9,0,0, 0,0,2,7,0,0,0,0,0, 0,0,0,0,5,0,1,3,0, 0,0,3,6,0,0,0,9,0, 8,0,0,0,0,0,4,0,7, 0,4,0,0,0,7,0,0,0 }; vector puzzle(&p[0], &p[81]); Zerodlx zerodlx(3, 1); int solns = zerodlx.solve(puzzle);
        for (int i = 0; i < 81; i++)
        cout << puzzle.at(i);
       cout << endl; }
