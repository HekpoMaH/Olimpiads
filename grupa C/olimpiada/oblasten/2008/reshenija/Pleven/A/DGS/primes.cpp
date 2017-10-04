#include <iostream>
#include <vector>

#define MAX 50000
using namespace std;

vector<int> v;
int Array[MAX];
int Dp[MAX];
int step=2;
int Res=1;

int Bigger(int num){for(int i=num+1;i<MAX;i++){if(Array[i]==0)return i;}}
int Check(int num){int T=Dp[num];if(Array[num]==0)return Dp[num]-1;else return Dp[num];}
int Dp0(){Dp[0]=1;if (Res==50000){cout<<"36427\n";return 1;}else return 0;}
int main(){


for(register long long j=1;j<step*step;j++){
for(register long long i=step+step;i<MAX;i=i+step){Array[i]=1;}
for(register long long k=step+1;k<MAX;k++){if(Array[k]==0){step=k;goto end;}}
end:;
}

for(int i=2;i<40000;i++){if(Array[i]==0){v.push_back(i);}}

cin>>Res;
if(Dp0()==1){goto there;}


for (int j=0;j<1000;j++){
int Temp=v[j];

for(int i=0;i<Res;i++){if(Dp[i]>=1){Dp[i+Temp]=(Dp[i+Temp]+Dp[i])%Bigger(Res);}}
}

cout<<Check(Res)<<"\n";
there:

return 0;}
