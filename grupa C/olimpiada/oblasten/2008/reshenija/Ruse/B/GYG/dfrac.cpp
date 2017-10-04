#include<iostream>
using namespace std;
int main(){
    long long a,b,k,p;
    cin >> a >> b >> k >> p;
    int ost=a%b,d[200000]={0},br=0,o=ost;
    while(ost!=0 && (o!=ost || br==0)){
                 int z=-1;
                 while(ost<b){z++;ost*=10;}
                 for(int i=0;i<z;i++){d[br]=0;br++;}
                 d[br]=ost/b;
                 br++;
                 ost%=b;
                 }
    if(ost==0){
               if(k<=br){
                         for(int i=k-1;i<br && i-k<p;i++) cout << d[i];
                         for(int i=0;i<k+p-br-1;i++) cout << 0;
                         }
                         else for(int i=0;i<p;i++) cout << 0;
               }else{
                     k=(k-1)%br;
                     for(int i=0;i<p;i++){
                             cout << d[k];
                             k++;
                             if(k==br) k=0;
                             }
                     }
    cout << endl;
    return 0;
}
