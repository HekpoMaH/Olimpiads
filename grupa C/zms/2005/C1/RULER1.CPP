#include <iostream.h>

void drawOneTick(int length, int number=-1)
{ for(int i=1; i<=length; i++) cout << "-";
  if(number>=0) cout << " " << number;
  cout << endl;
}

void drawTicks(int length)
{ if(length>0)
  { drawTicks(length-1);
    drawOneTick(length);
    drawTicks(length-1);
  }
}

void main()
{ int n, m;
  cin >> n >> m;

  drawOneTick(m,0);
  for(int i=1; i<=n; i++)
  { drawTicks(m-1);
    drawOneTick(m,i);
  }
}
