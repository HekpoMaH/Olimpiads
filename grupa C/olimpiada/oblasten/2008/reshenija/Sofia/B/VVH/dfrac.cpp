#include <iostream>
using namespace std;
char mas[3000000];
long a,b;
long long k,p;                
int main(){
    int i,j,l;
    cin>>a>>b>>k>>p;
    a=a%b;
    int sa=a;
    long nap=1;
    while(1){
             a=a*10;
             a=a%b;
             if(mas[a]==0) {mas[a]=nap;nap++;}
             else break; 
            }
    int beg,end;
    beg=mas[a]+1;
    end=nap;
    int nachalo=sa;
    int xxx;
    for(i=1;i<beg;i++) {nachalo=nachalo*10;
                         nachalo=nachalo%b;
                       }
    int a1=sa;
    if(k<beg){
              for(i=1;i<k;i++){a1=a1*10;a1=a1%b;}
              for(i=k;i<beg;i++) {a1=a1*10;cout<<a1/b;a1=a1%b;}
              p=p-(beg-k);
              k=beg;
             }
    int x=nachalo;
    int from=(k-beg+1)%(end-beg+1);
    for(i=1;i<from;i++){x=x*10;
                        x=x%b;
                       }                 
    for(i=1;i<=p;i++) {x=x*10;
                       cout<<x/b;
                       x=x%b;
                      }
    cout<<'\n';                      
    //system("pause");
    return 0;
}        
             
