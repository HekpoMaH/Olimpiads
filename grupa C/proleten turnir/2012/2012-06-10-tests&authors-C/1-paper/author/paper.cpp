// Task - paper
// Author - Pano Panov
//
#include <iostream>
#define LM 60
#define LN 50

using namespace std;
int a[LM][LN];
int m, n, k, ind, S=0, flg=1;

void DataEntry()
{
 int i, j;
 cin>>m>>n>>k;
 for(i=0; i<m; i++)
    for(j=0; j<n; j++) a[i][j]=1;

 for(ind=0; ind<k; ind++)
    {
     cin>>i>>j;
     a[i-1][j-1]=0;
    }
}

void FillPart(int i, int j)
{
 a[i][j]=flg;

 if((i > 0)   && (a[i-1][j]==1)) FillPart(i-1,j);
 if((i < m-1) && (a[i+1][j]==1)) FillPart(i+1,j);
 if((j > 0)   && (a[i][j-1]==1)) FillPart(i,j-1);
 if((j < n-1) && (a[i][j+1]==1)) FillPart(i,j+1);
}

int main()
{
 int i, j;
 DataEntry();

 for(i=0; i<m; i++)
    for(j=0; j<n; j++)
       {
         if(a[i][j]==1)
           {
            flg++;
            FillPart(i,j);
            S++;
           }
        }
 cout <<S<<endl;
 return 0;
}

