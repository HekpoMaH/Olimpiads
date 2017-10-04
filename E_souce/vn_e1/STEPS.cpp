#include<iostream>
using namespace std;
int main () {
    int N,H,L;
    char S;
    cin>>N>>H>>L>>S;
       for (int i=1;i<=N*H-N+1;i++) {
           for (int j=1;j<=N*L;j++) {
               if (j==1||i==N*H-N+1||(j%L==1&&i==H)) cout<<S;
            
                                           
               }
               cout<<endl;
               }
        
            //system ("pause");
            return 0;
            }
