#include <cstdlib>
#include <iostream>
#include <iomanip>
#define MAXINT 0x7FFFFFFF
using namespace std;
double s[500];
double d[500];
double a[500];
int groupranges[500];
int n,p;

int getupperrange(int group){
       return groupranges[group];
}
int getlowerrange(int group){
       if (group == 0) return 0;
       else return (groupranges[group-1]+1);
}
void setrange(int group,int upper,int down){
     //groupranges[2*group]= down;
     //groupranges[2*group+1]= upper;
}
double run(){
      double t;
      int g,i;
      for(g=0;g<p;g++){
          int ec,ugr,dgr;
          double b;
          //Smetane na S
          ugr = getupperrange(g);
          dgr = getlowerrange(g);
          ec = ugr-dgr+1;
          s[g]=0;
          d[g]=0;
          for(i=dgr;i<=ugr;i++){s[g]+=a[i];}s[g]/=ec;
          for(i=dgr;i<=ugr;i++){b=a[i]-s[g];d[g]+=b*b;}
      }
      t=0.0;for(g=0;g<p;g++)t+=d[g];
      return t;
}
int isrising(){
    int i;
    for (i=0;i<p-1;i++)if(groupranges[i]>groupranges[i+1])break;
    return (groupranges[i]>groupranges[i+1]);
}
double cycle(){
   int i;
   double t,mn=99999;
   int mx = p-1;
   int mx2 = p-2;
   groupranges[mx2]++;
   for (i=mx2;i>=0;i--){
   if(groupranges[i]>mx2){
     groupranges[i]=0;
     groupranges[i-1]++;
   }
    if(isrising()){
     t=run();
     if(t<mn)mn=t;
    }
   }
   return mn;
}

int main(int argc, char *argv[])
{   
    int i;
    double min;
    //Input
    cin >> n >> p;for (i=0;i<n;i++)cin >> a[i];
    //Range initialization
    for(int g=0;g<p-1;g++){
      groupranges[g]=0;
    }
    groupranges[p-1]=n-1;
    
    //Main
    min = cycle();     
    //Output
    cout << min << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
