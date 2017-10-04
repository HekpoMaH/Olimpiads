#include<iostream>
#include<math.h>
using namespace std;
int max(int a,int b){
  if(a>b) return a;
  else return b;
}
int min(int a,int b){
  if(a<b) return a;
  else return b;
}
int Dist(int a,int b,int c,int d){
  return max(abs(a-c),abs(b-d)); // Min Distance between 2 points
}
int main()
{
  int Final=100000,Current=0,n,P[13][2],i=0,map[13][13];
  cin >> n; P[0][0]=0; P[0][1]=0;
  for(i=1;i<=2*n;i++) cin >> P[i][0] >> P[i][1];
  for(int x=0;x<=2*n;x++) for(int y=x+1;y<=2*n;y++) {map[x][y]=Dist(P[x][0],P[x][1],P[y][0],P[y][1]);} // set matrix values x>y
  if(n==1) Final=min(Dist(P[1][0],P[1][1],0,0),Dist(P[2][0],P[2][1],0,0));
  if(n==2) {
  for(int L1=1;L1<=2*n;L1++) for(int L2=1;L2<=2*n;L2++) if(L1!=L2) {
    Current=map[min(0,L1)][max(0,L1)]+map[min(L1,L2)][max(L1,L2)];
    if(Final>Current) Final=Current;
    }
  }
  if(n==3) {
  for(int L1=1;L1<=2*n;L1++) for(int L2=1;L2<=2*n;L2++) if(L1!=L2) for(int L3=1;L3<=2*n;L3++) if(L3!=L1 && L3!=L2){
    Current=map[min(0,L1)][max(0,L1)]+map[min(L1,L2)][max(L1,L2)]+map[min(L2,L3)][max(L2,L3)];
    if(Final>Current) Final=Current;
    }
  }
  if(n==4) {
  for(int L1=1;L1<=2*n;L1++) for(int L2=1;L2<=2*n;L2++) if(L1!=L2) for(int L3=1;L3<=2*n;L3++) if(L3!=L1 && L3!=L2) for(int L4=1;L4<=2*n;L4++) if(L4!=L1 && L4!=L2 && L4!=L3){
    Current=map[min(0,L1)][max(0,L1)]+map[min(L1,L2)][max(L1,L2)]+map[min(L2,L3)][max(L2,L3)]+map[min(L3,L4)][max(L3,L4)];
    if(Final>Current) Final=Current;
    }
  }
  if(n==5) {
  for(int L1=1;L1<=2*n;L1++) for(int L2=1;L2<=2*n;L2++) if(L1!=L2) for(int L3=1;L3<=2*n;L3++) if(L3!=L1 && L3!=L2) for(int L4=1;L4<=2*n;L4++) if(L4!=L1 && L4!=L2 && L4!=L3) for(int L5=1;L5<=2*n;L5++) if(L5!=L1 && L5!=L2 && L5!=L3 && L5!=L4){
    Current=map[min(0,L1)][max(0,L1)]+map[min(L1,L2)][max(L1,L2)]+map[min(L2,L3)][max(L2,L3)]+map[min(L3,L4)][max(L3,L4)]+map[min(L4,L5)][max(L4,L5)];
    if(Final>Current) Final=Current;
    }
  }
  if(n==6) {
  for(int L1=1;L1<=2*n;L1++) for(int L2=1;L2<=2*n;L2++) if(L1!=L2) for(int L3=1;L3<=2*n;L3++) if(L3!=L1 && L3!=L2) for(int L4=1;L4<=2*n;L4++) if(L4!=L1 && L4!=L2 && L4!=L3) for(int L5=1;L5<=2*n;L5++) if(L5!=L1 && L5!=L2 && L5!=L3 && L5!=L4) for(int L6=1;L6<=2*n;L6++) if(L6!=L1 && L6!=L2 && L6!=L3 && L6!=L4 && L6!=L5){
    Current=map[min(0,L1)][max(0,L1)]+map[min(L1,L2)][max(L1,L2)]+map[min(L2,L3)][max(L2,L3)]+map[min(L3,L4)][max(L3,L4)]+map[min(L4,L5)][max(L4,L5)]+map[min(L5,L6)][max(L5,L6)];
    if(Final>Current) Final=Current;
    }
  }
  cout << Final << endl;
  return 0;
}