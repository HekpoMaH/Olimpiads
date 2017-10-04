#include<iostream>
using namespace std;
int n;
int data[5];
int main(void){
  cin>>n;
  for(int i=0;i<n;i++)cin>>data[i];
  for(int x=1;x<=500;x++){
     for(int y=x;y<=2*x;y++){
        int cand[4]={x,y,4*x-y,3*x};
        bool visited[4]={0,0,0,0};
        int cnt=0;
        for(int i=0;i<n;i++){
           for(int j=0;j<4;j++){
              if(!visited[j]&&cand[j]==data[i]){visited[j]=1;cnt++;break;}
           }
        }
        if (cnt ==n){
           cout<<"YES\n";
           for(int i=0;i<4;i++){
             if(!visited[i])cout<<cand[i]<<endl;
           }
           return 0;
        }
     }
  }
  cout<<"NO\n";
  return 0;
}
