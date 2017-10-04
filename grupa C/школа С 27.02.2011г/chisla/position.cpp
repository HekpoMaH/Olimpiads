#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip>
#include <stdlib.h>
#include <fstream>

#define SP system("pause")
#define MAXN 32767

using namespace std;

int main()
{
    int k;
    long long int pos = 0;
    long long int cd = 1;
    long long int num = 1;
    long long int range = 10;
    
    cin >> k;
    do//tozi cikyl se vyrti dokato ne dostignem trsenata poziciq
    {
        while ( num * num < range && pos < k )//generirame vsi4ki ednocifreni, dvucifreni i t.n. kvadrati
                                                // dokato dostignem poziciq k ili ve4e kvadrata izleze ot 
                                                //obhvata naprimer ako obhvata ni e ednocifreno 4islo
                                                //to togava kogato num stane 4 to 4^2 = 16 i taka izlizame 
                                                //ot obhvata koito sme zaplanuvali da proverim
        {
            num++;//vzimame sledva6toto 4islo 4iito kvadrat iskame da proverim
            pos += cd;//uveli4avame poziciqta
        }
            range *= 10;//vzemame sledva6tiqt obhvat 
            cd++;//uveli4avame dyljinata na sledva6tata grupa 4isla
    }while ( pos < k );
    
    long long int m = ( num - 1 ) * ( num - 1 );
    while ( pos - k >0 )//namirame to4no tyrsenata cifra na poziciq k
    {
        m /= 10;
        pos--;
    }
    cout << m % 10 << endl;
return 0;
}
