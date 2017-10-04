#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a[5],i,fl=0,p,sqr,ab,b=0,br=0,cpy;
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    if(a[1]!=0){
                if(a[2]!=0){
                            fl=1;
                            a[3]=a[1]*a[1]*a[2];
                            a[4]=a[1]*a[2]*a[2];
                            cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
                            }
                if((a[3]!=0)&&(fl==0)){
                                       fl=1;
                            a[2]=a[3]/(a[1]*a[1]);
                            a[4]=a[1]*a[2]*a[2];
                            cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
                            }
                if((a[4]!=0)&&(fl==0)){
                            fl=1;
                            a[2]=(-1)*(abs(sqrt(a[4]/a[1])));
                            a[3]=a[1]*a[1]*a[2];
                            cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
                            }
                            }
    if((a[2]!=0)&&(fl==0)){
                if(a[3]!=0){fl=1;
                            a[1]=(-1)*(abs(sqrt(a[3]/a[2])));
                            a[4]=a[1]*a[2]*a[2];
                            cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
                            }
                if((a[4]!=0)&&(fl==0)){fl=1;
                                       a[1]=a[4]/(a[2]*a[2]);
                                       a[3]=a[2]*a[1]*a[1];
                                       }}
    if((a[3]!=0)&&(fl==0)){
                           if(a[4]!=0){fl=1;
                                      p=a[3]*a[4];
                                      for(i=2;;i++)if(i*i*i==p)break;
                                      a[1]=a[3]/i;
                                      a[2]=a[4]/i;
                                      cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;}
                           else {
                                fl=1;
                                cpy=a[3];
                                for(i=2;;i++){
                                 if(cpy%i==0){cpy/=i;
                                              if(i==b)break;
                                              else b=i;
                                              i--;
                                              }}
                                 if((-1)*b>=a[3]/(b*b))a[1]*=-1;
                                 else a[1]=b;
                                 a[2]=a[3]/(a[1]*a[1]);
                                 a[4]=a[1]*a[2]*a[2];
                                 cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;}}
    if(fl==0){
              if(sqrt(a[4])*sqrt(a[4])==a[4]){
                                              a[2]=(-1)*(abs(sqrt(a[4])));
                                              a[1]=a[4]/(a[2]*a[2]);
                                              a[3]=a[1]*a[1]*a[2];
                                              cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;}
              else {cpy=a[4];
                   for(i=2;;i++){
                                 if(cpy%i==0){cpy/=i;
                                              if(i==b)break;
                                              else b=i;
                                              i--;
                                              }}
                   a[2]=(-1)*b;
                   a[1]=a[4]/(a[2]*a[2]);
                   a[3]=a[1]*a[1]*a[2];
                   cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;}}
    //system("pause");
    return 0;}
