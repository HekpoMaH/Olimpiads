#include<iostream>
using namespace std;
int main() {
long long botilki[2],polycenres;
cin>>botilki[0]>>botilki[1];
polycenres=botilki[0]*botilki[1];
polycenres=(polycenres/(botilki[0]+botilki[1]))*2;
cout<<polycenres;
return 0;
}
