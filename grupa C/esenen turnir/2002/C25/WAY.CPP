#include <fstream.h>

int n,a[15][15],k,l;



void init()
{ int i,j,b,c,d;
  cin >> n;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      a[i][j]=0;
/*  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      cout  << a[i][j]; */
  if(n>2)
    { cin >> b >> c >> d;
      while(!fin.fail())
	{ if(d==1)
	    { a[b][c]=1;
	      a[c][b]=1;
	    }
	  cin >> b >> c >> d;
	}
     }
  k=b;
  l=c;
}

void main()
{ int b,c,d;
  init();
  if(n==1)
    { cout << "1";
      cout << endl << "1";
    }
  cout << endl;
  if(n==2)
    { fin >> b >> c >> d;
      a[b][c]=d;
      if(a[b][c]==1)
	cout << "2" << endl << "1 2";
      else
	if(a[b][c]==0)
	  cout << "0";
     }
  if(a[k][l]==1 || a[l][k]==1)
    cout << "2" << endl << k << " "<< l;



}