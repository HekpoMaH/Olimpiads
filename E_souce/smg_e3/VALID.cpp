//VALID
#include<iostream>
using namespace std;
int main() {
    int dd, mm, gggg, next_d, next_m, next_y, valid=1, days;
    cin>>dd>>mm>>gggg;
    next_d=dd;
    next_m=mm;
    next_y=gggg;
    if (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12) {
          if (dd>31) { valid=0; days=31; }
          if (dd==31) {
                      next_d=1;
                      if (next_m+1==13) { next_y++;next_m=1; }
                      else next_m++;
          }
          if (dd<31) next_d++;
    }
    if (mm==2) { if (dd>29) { valid=0; days=29; }
       if (dd==29) {
          next_d=1;
          if (next_m+1==13) { next_y++; next_m=1; }
          else next_m++;
       }
       if (dd<29) next_d++;
    }
    if (mm==4 || mm==6 || mm==9 || mm==11) {
          if (dd>30) { valid=0; days=30; }
          if (dd==30) {
                      next_d=1;
                      if (next_m+1==13) { next_y++;next_m=1; }
                      else next_m++;
          }
          if (dd<30) next_d++;
    }
    if (valid==1) { cout << "Yes" << endl << next_d << "." << next_m << "." << next_y; }
    else cout << "No" << endl << days;
    cout << endl;
    return 0;
}
