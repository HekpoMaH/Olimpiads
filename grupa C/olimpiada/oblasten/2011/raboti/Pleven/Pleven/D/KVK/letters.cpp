#include<iostream>
#include<string>
#include<cstring>
using namespace std;
long long n,i,br1,br2,br,br3,br4,j,d;
char a,a1;
string s[10001][5];
int main () {
cin>>n>>a;
a1=a-32;
for(i=1;i<=n;i++) {
 for(j=1;j<=4;j++) {
  cin>>s[i][j];
 }
}
for(i=1;i<=n;i++) {
 if(s[i][1][0]==a || s[i][1][0]==a1) {
  br1++;
 }
}
for(i=1;i<=n;i++) {
 d=s[i][2].size();
 for(j=0;j<=d-1;j++) {
  if(s[i][2][j]==a || s[i][2][j]==a1) {
   br2++;
   break;
  }
 }
}
for(i=1;i<=n;i++) {
 d=s[i][3].size();
 for(j=0;j<=d-1;j++) {
  if(s[i][3][j]==a || s[i][3][j]==a1) {
   br++;
  }
 }

 if(br>=2) {
  br3++;
 }
 br=0;
}
cout<<br1<<" "<<br2<<" "<<br3;
for(i=1;i<=n;i++) {
 d=s[i][4].size();
  if(s[i][4][d-1]==a || s[i][4][d-1]==a1) {
   br4++;
  }
 }

cout<<" "<<br4<<endl;
  return 0;
}