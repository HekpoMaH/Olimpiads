#include <iostream.h>

void drawtick(int length, int number=-1)
{ for(int i=1; i<=length; i++)
    cout << "-";
  if(number>=0) cout << " " << number;
  cout << endl;
}

void main()
{ int n, m;
  cin >> n >> m;

  drawtick(m,0);
  for(int i=1; i<=n; i++)
  { for(int j=1; j < 1<<(m-1); j++)
      { int w=j, k=1;
        while(w%2==0)
          { w/=2; k++;}
        drawtick(k);
      }
    drawtick(m,i);
  }

}
