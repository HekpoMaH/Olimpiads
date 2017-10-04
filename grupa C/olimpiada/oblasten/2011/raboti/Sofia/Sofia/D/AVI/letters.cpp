#include<iostream>
#include<string>
using namespace std;
int main(){
char a;
int broi,r1=0,r2=0,r3=0,r4=0;
string dumi[4];
cin>>broi>>a;
for(int i=0;i<broi;++i){
    cin>>dumi[0]>>dumi[1]>>dumi[2]>>dumi[3];
    if(dumi[0][0]==a||dumi[0][0]==a-32){
       ++r1;
    }
    for(int j=0;dumi[1][j];++j){
    if(dumi[1][j]==a||dumi[1][j]==a-32){
       ++r2;break;
    }

}
int broi2=0;
    for(int j=0;dumi[2][j];++j){
    if(dumi[2][j]==a||dumi[2][j]==a-32){
       ++broi2;
    }
    if(broi2==2){++r3;break;}
}
int h=0;
    for(int j=0;dumi[3][j];++j){
      h=j;
    }
    if(dumi[3][h]==a||dumi[3][h]==a-32){
       ++r4;
    }

}
cout<<r1<<' '<<r2<<" "<<r3<<" "<<r4<<endl;
return 0;
}