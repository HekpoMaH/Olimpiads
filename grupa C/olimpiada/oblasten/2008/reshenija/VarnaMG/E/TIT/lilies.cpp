# include <iostream>
using namespace std;
int main() {
    int n,a,min=21,d1,d2,d3,d4,d5,d6,d7;
    cin>>a;
    if(a==2){
    cin>>d1>>d2;
    if(d1<=d2)
    cout<<d1*2<<endl;
    if(d2<=d1)
          cout<<d2*2<<endl; }
    else if(a==3) {
    cin>>d1>>d2>>d3;
    if(d1<=min)
    min=d1;
      if(d2<=min)
    min=d2;
        if(d3<=min)
    min=d3;
    cout<<min*3<<endl; }
        else if(a==4) {
    cin>>d1>>d2>>d3>>d4;
    if(d1<=min)
    min=d1;
      if(d2<=min)
    min=d2;
        if(d3<=min)
    min=d3;
            if(d4<=min)
    min=d4;
    cout<<min*4<<endl; }
            else if(a==5) {
    cin>>d1>>d2>>d3>>d4>>d5;
    if(d1<=min)
    min=d1;
      if(d2<=min)
    min=d2;
        if(d3<=min)
    min=d3;
            if(d4<=min)
    min=d4;
              if(d5<=min)
    min=d5;
    cout<<min*5<<endl; }
                else if(a==6) {
    cin>>d1>>d2>>d3>>d4>>d5>>d6;
    if(d1<=min)
    min=d1;
      if(d2<=min)
    min=d2;
        if(d3<=min)
    min=d3;
            if(d4<=min)
    min=d4;
              if(d5<=min)
    min=d5;
                  if(d6<=min)
    min=d6;
    cout<<min*6<<endl; }
                    else if(a==7) {
    cin>>d1>>d2>>d3>>d4>>d5>>d6;
    if(d1<=min)
    min=d1;
      if(d2<=min)
    min=d2;
        if(d3<=min)
    min=d3;
            if(d4<=min)
    min=d4;
              if(d5<=min)
    min=d5;
                  if(d6<=min)
    min=d6;
                      if(d7<=min)
    min=d7;
    cout<<min*6<<endl; }

    //system ("pause") ;
    return 0;
}
