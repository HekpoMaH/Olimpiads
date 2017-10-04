#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <ctime>

#define ROWS T[i][0]
#define COLS T[i][1]
#define K T[i][2]
#define SR T[i][3]
#define SC T[i][4]
#define MAXV T[i][5]
#define UPBY T[i][6]

using namespace std;

int T[10][7] = {
//rows, cols,  k, sr, sc, maxval, up_by
  { 10,  20,   3,   6,  15,  10,  20 },
  { 20,  30,   7,  11,  20, 100, 300 },
  { 60,  80,  47,   5,  12, 400, 401 },
  {100, 100,  50,  29,  49,  55, 100 },
  {183,  92,  51, 101,  33, 218, 305 },
  {200, 401,  17, 145, 322, 450, 451 },
  {480, 500, 245, 201, 245, 360, 361 },
  {717, 590, 500,   3,  27,   1,   1 },
  {800, 799, 400, 400, 399, 200, 201 },
 {1000,1000, 500,  63, 417, 500, 500 }
};


int A[1000][1000];

void fill_equ(int sr, int rows, int sc, int cols, int val){
  for (int i= sr; i < sr+rows; i++) for (int j=sc; j<sc+cols; j++) A[i][j] = val;
}

int fill_rand(int rows, int cols, int maxval=1000){
  int sum=0, i, j;
  for (i= 0; i < rows; i++) for (j=0; j<cols; j++) sum += (A[i][j] = rand()%maxval + 1);
  return sum;
}

int up_by(int k, int sr, int sc, int by=0){
  int sum=0, i, j, ie=sr+k, je=sc+k;
  for (i= sr; i < ie; i++) for (j=sc; j<je; j++) sum += (A[i][j] += by);
  return sum;
}

void write_in_file(ofstream& fin, int r, int c, int k){
  int i, j;
  fin << r << " " << c << " " << k << endl;
  for (i=0 ; i < r; i++){
    fin << A[i][0];
    for (j=1; j < c; j++) fin << " " << A[i][j];
    fin << endl;
  }
}
int main(){

  char namein[50]="roses.00.in", namesol[50]="roses.00.sol";
  ofstream fin, fsol;

  srand(time(NULL));

  fin.open(namein);
  fsol.open(namesol);
  fin << "3 4 2\n1 1 1 2\n2 3 4 1\n2 1 9 2\n";
  fsol << "12\n";
  fin.close();
  fsol.close();

  for (int i=0;i<10;i++) {
    sprintf(namein,"roses.%02i.in",i+1);
    sprintf(namesol,"roses.%02i.sol",i+1);
    fin.open(namein);
    fsol.open(namesol);
    fsol<< fill_rand(ROWS, COLS, MAXV ) + K*K*UPBY - up_by(K, SR, SC, UPBY)<< endl;
    write_in_file(fin, ROWS, COLS, K);
    fin.close();
    fsol.close();
  }

  return 0;
}
