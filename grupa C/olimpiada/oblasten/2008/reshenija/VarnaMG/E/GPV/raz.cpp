#include<iostream>
using namespace std;
int main () {
    long long int del1,del2,N,min_razlika,br=0,razlika;
    cin>>N;
    for (del1=1;del1<=N;del1++) {
        for (del2=del1;del2<=N/del1;del2++) {
            if (del1*del2==N) {
                br++;
                if (br==1) min_razlika=del2-del1;
                razlika=del2-del1;
            if (min_razlika>razlika) min_razlika=razlika;  
        }
    }
}
    for (del1=1;del1<=N;del1++) {
        for (del2=del1;del2<=N/del1;del2++) {
            if (del1*del2==N)
            if (del2-del1==min_razlika) cout<<del1<<" "<<del2<<endl;
            }
    }
   //system ("pause");
   return 0;
}
