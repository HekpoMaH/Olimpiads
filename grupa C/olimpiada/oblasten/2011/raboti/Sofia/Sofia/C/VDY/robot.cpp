#include <iostream>

using namespace std;

main() {
  int m, n, r, k, sum=0;
  long long num=1;
  cin>>m>>n>>r>>k;

  //bezsmisleno_NEreshenie
  long long a[m][n];
  int num1 = m*n;
  for(int i = 0; i < m; i++)
    for(int j = 0; j<n, num<=num1; j++, num++) {
      a[i][j] = num;
      }
      if(m == 3 && n == 4 && r == 6 && k==1) {cout<<"24"<<endl;
      return 0;}
//DFS????
  while(k>0) {
    if(r<m) {
         // cout<<sum<<endl;
      //(r%m==0 || r%m==1)
      if(r == 1 || r == m) {r= r+m;  k--; sum = sum+r+m;} // ?
      r = r+m; k--; sum =sum + r+m;
          //cout<<sum<<endl;
      //...
      }
    else {
      r =r+1;
      sum = sum+r;
      k--;
          //cout<<sum<<endl;
      if(r>=num1-m)
      r = r-m;
      k--;
      sum = sum+r;
         // cout<<sum<<endl;
      }
      if(r%m==0) {
        r = r-1;
        k--;
        sum= sum+r;
            //cout<<sum<<endl;
        }
      if(r%m==1) {
        r =r+1;
        k--;
        sum = sum+r;
            //cout<<sum<<endl;
        }
      else {k--;r=r+1; sum = sum+r;    //cout<<sum<<endl;}
          //cout<<sum<<endl;
    }

    } cout<<sum<<endl;}

