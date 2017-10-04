#include <iostream>
using namespace std;
int main()
{int a,b,c,d,e,t;
 cin>>a>>b>>c>>d>>e;
 if (a>b){t=a;a=b;b=t;}
 if (a>c){t=a;a=c;c=t;}
 if (a>d){t=a;a=d;d=t;}
 if (a>e){t=a;a=e;e=t;}
 if (b>c){t=b;b=c;c=t;}
 if (b>d){t=b;b=d;d=t;}
 if (b>e){t=b;b=e;e=t;}
 if (c>d){t=c;c=d;d=t;}
 if (c>e){t=c;c=e;e=t;}
 if (d>e){t=d;d=e;e=t;}
 if (b==a+1 && c==b+1 && d==c+1 && e==d+1)
 {cout<<"Straight\n";return 0;}
 t=0;
 if (a==b) t++;
 t*=2;
 if (b==c) t++;
 t*=2;
 if (c==d) t++;
 t*=2;
 if (d==e) t++;
 switch (t)
 {case 0:{cout<<"Nothing\n";break;}
  case 15:{cout<<"Impossible\n";break;}
  case 1:case 2:case 4:case 8:{cout<<"One Pair\n";break;}
  case 7:case 14:{cout<<"Four of a Kind\n";break;}
  case 3:case 6:case 12:{cout<<"Three of a Kind\n";break;}
  case 11:case 13:{cout<<"Full House\n";break;}
  default:cout<<"Two Pairs\n";
 }
 return 0;
}