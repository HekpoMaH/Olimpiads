//SYSADMIN
//Nikolina Nikolova

#include <iostream>
#include <cstring>


using namespace std;

union code{
    int N;
    char chars4[4];
};

code sepIP();  //separates the four numbers
                //keeping them respectively in the chars4 array
void print4Chars(code); //outputs characters corresponding to the given code
void turnLeft(code &, int); //turs given code given positionsleft
char ip[16];
int main()
{
    int K;
    scanf("%d", &K);

    while (scanf("%s", &ip) == 1)
    {
        code ipSep;
        ipSep = sepIP();
        turnLeft(ipSep,K);
        print4Chars(ipSep);
    }






    cout << endl;
    return 0;
}

code sepIP(){
    char *p, *q;
    p = ip;
    code myCode;
    for (int i = 3; i > 0; i--){
        q = p;
        p = strchr(p,'.');
        *p = '\0'; p++;
        myCode.chars4[i]=atoi(q);
    }
    myCode.chars4[0]=atoi(p);

    return myCode;
}

void print4Chars(code myCode){
    for (int i = 3; i>=0; i--)
    printf("%c", myCode.chars4[i]);
}

void turnLeft(code &myCode, int K){
    int left = myCode.N >> (32 - K);
    int mask = (1 << K)-1;
    left &= mask;
    myCode.N <<= K;
    myCode.N |= left;
}
