#include <iostream>

using namespace std;

int main() {
    long long int a, b, k, p, chr, ost, del;
    cin >> a >> b;
    cin >> k >> p;
    // 4islata sa vavedeni
    ost = a;

    // FOR-a varti ot 0 do k+p t.e. samo do poslednoto 4islo koeto 6te izkarva    
    for (int i=1;i<k+p;i++){ 
              
        ost *= 10;
        chr = ost/b;
        del = chr*b;
        ost -= del; 
        
        // ako i e v intervala mezdu K i P obozna4ava s "ans:"        
        if (i>=k){
           cout << chr;
        }
   
    }


cout << endl;
return 0;
}
