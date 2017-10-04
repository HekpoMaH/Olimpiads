#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
double a,x;
long long br;
bool l;
int main()
{
    int max = -1;
    cin >> a;
    x = a;
    cin >> a;
    while(a != 0){
        l = 0;
        if(x > a)l = 1;
        if(br > max)max = br;
        if(l == 0)br++;
        else br = 0;
        x = a;
        cin >> a;
    }
    cout << max+1 << endl;
    return 0;
}