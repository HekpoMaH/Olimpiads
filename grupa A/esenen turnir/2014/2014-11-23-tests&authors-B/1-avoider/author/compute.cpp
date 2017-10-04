// modified by Emil Kelevedjiev of the original program by Stephen A. Silver

/*
 *  Sloane's sequence A046170.
 *
 *  Self-avoiding walks of length n on Z^2 starting from (0,0), then moving
 *  to (1,0) and staying in the quadrant with non-negative coordinates.
 *
 *  For reasons of efficiency this program actually considers the walk to
 *  start at (1,1), move to (2,1) and then stick to postive coordinates.
 *
 *  Unless the counting type defined below is changed, this may only work
 *  for n<=25, depending on the compiler used.
 *
 *  Stephen A. Silver, 2000 Jun 14.
 */

#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long COUNTTYPE;
#define CTFORMAT "%llu"

/*
 *  MAXN is the maximum allowable value of n.  For efficiency it should
 *  usually be 2 less than a power of 2.  62 suffices for all n that
 *  are computationally feasible.
 */
#define MAXN 62


/*
 *  The isfree array (once initialized) contains 1 for every point that
 *  is free, and 0 for those which are not free (including all points
 *  with a 0 coordinate).  The type can be any of unsigned char, unsigned
 *  short, or unsigned int without affecting the code that uses it.
 */
unsigned char isfree[MAXN+2][MAXN+2];


/*
 *  A global variable that stores the n for which we car computing
 *  A046170(n).
 */
int n;


/* A small speed-up when compiled with DJGPP */
#ifdef __DJGPP__
static COUNTTYPE NumberFrom(int,int,int) __attribute__ ((regparm(2)));
#endif


/*
 *  This macro is used in NumberFrom to add the appropriate number
 *  to the count for the direction under consideration.
 */
#define INCCOUNT(m,x,y)             \
    if (isfree[x][y]) {             \
        isfree[x][y] = 0;           \
        count += NumberFrom(m,x,y); \
        isfree[x][y] = 1;           \
    }


/*
 *  Count the number of valid walks of length n that are formed by
 *  extending the current walk of length m.
 *
 *  On entry: 0 < m < n
 *    and (x,y) is the current position.
 */
static COUNTTYPE
NumberFrom(int m, int x, int y)
{
    COUNTTYPE count;
    const int m1 = m+1;

    /* Deal with end case */
    if (m1==n)
        return  isfree[x+1][y]
              + isfree[x][y+1]
              + isfree[x-1][y]
              + isfree[x][y-1];

    /* Deal with non-end cases */
    count = 0;
    x++;
    INCCOUNT(m1,x,y);   /* right */
    x -= 2;
    INCCOUNT(m1,x,y);   /* left  */
    x++;
    y++;
    INCCOUNT(m1,x,y);   /* up    */
    y -= 2;
    INCCOUNT(m1,x,y);   /* down  */

    /* Return the total count */
    return count;
}


/*
 *  Show correct usage and exit.
 */
static void
ShowUsage(void)
{
    fprintf(stderr,"Usage:  <program> <n>\n"
        "  where <n> is the length of the walks.\n");
    exit(EXIT_FAILURE);
}


/*
 *  Show the result.
 */
void
ShowResult(COUNTTYPE count)
{
   // printf("Number of valid walks of length %d is ",n);
    printf("%d: ",n);
    printf(CTFORMAT,count);
   // printf(".");
    printf("\n");
}


/*
 *  main()
 */
int
main(int argc, char* argv[])
{
    int x,y;

    /* Process command line arguments */
    if (argc!=2) ShowUsage();
    n = atoi(argv[1]);
    if (n<=0) ShowUsage();
    if (n<=2) {
        ShowResult(n);
        return 0;
    }
    if (n>MAXN) {
        fprintf(stderr,"n too large (maximum allowed is %d).\n",MAXN);
        exit(EXIT_FAILURE);
    }

    /* Initialize */
    for(x=0;x<MAXN+2;x++) {
        for(y=0;y<MAXN+2;y++) {
            isfree[x][y] = (y>0 && x>0);
        }
    }
    isfree[1][1] = 0;
    isfree[2][1] = 0;

    /* Compute and display result */
    ShowResult(NumberFrom(1,2,1));

    return 0;
}
