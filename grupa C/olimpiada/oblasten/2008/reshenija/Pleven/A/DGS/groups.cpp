#include <iostream>
#include <vector>
#include <string>
using namespace std;

double Groups,Nums;
double Temp;
double Sa,Res;
vector<double> v;

int main(){

cin>>Nums>>Groups;
for(int i=0;i<Nums;i++){cin>>Temp;v.push_back(Temp);Sa+=Temp;}
if((int)Nums%2==1){v.push_back(Temp);Sa+=Temp;}
if(Nums==Groups)cout<<"0.0\n";
else if(Groups==1){Sa/=Nums;for(int i=0;i<Nums;i++){Res=Res+(v[i]-Sa)*(v[i]-Sa);}cout<<Res<<"\n";}
else{
Res=0;
for(int i=0;i<Nums/Groups;i++){Res=Res+v[i];}
Sa=Res/(Nums/Groups);
Res = 0;
for(int i=0;i<Nums/Groups;i++){Res=Res+(v[i]-Sa)*(v[i]-Sa);}

cout<<Res*Groups<<"\n";}
return 0;}
