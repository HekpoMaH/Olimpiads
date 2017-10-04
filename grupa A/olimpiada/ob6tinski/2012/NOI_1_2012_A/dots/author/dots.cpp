#include <iostream>
#include <cmath>
using namespace std;
int X_A,Y_A,X_B,Y_B,X_C,Y_C,X_D,Y_D;
long twiceArea(int X_A,int Y_A,int X_B,int Y_B,int X_C,int Y_C)
{return abs((X_B-X_A)*(Y_C-Y_A)-(X_C-X_A)*(Y_B-Y_A));
}
int solve()
{int sABC,sABD,sACD,sBCD,m;
 sABC=twiceArea(X_A,Y_A,X_B,Y_B,X_C,Y_C);
 sABD=twiceArea(X_A,Y_A,X_B,Y_B,X_D,Y_D);
 sACD=twiceArea(X_A,Y_A,X_C,Y_C,X_D,Y_D);
 sBCD=twiceArea(X_B,Y_B,X_C,Y_C,X_D,Y_D);
 switch (!sABC + !sABD + !sACD + !sBCD)
 {case 1:return 2;
  case 2:return 1;
  case 4:return 0;
  default:
  {m=sABC;
   if (sABD>m) m=sABD;
   if (sACD>m) m=sACD;
   if (sBCD>m) m=sBCD;
   if (2*m==sABC+sABD+sACD+sBCD) return 3;
   return 4;
  }
 }
}

int main()
{
 cin>>X_A>>Y_A>>X_B>>Y_B>>X_C>>Y_C>>X_D>>Y_D;
 cout<<solve()<<endl;
 return 0;
}
