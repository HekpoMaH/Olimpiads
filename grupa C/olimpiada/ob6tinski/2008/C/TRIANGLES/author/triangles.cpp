#include<iostream>

using namespace std;

int main()
{
    int P, a, b, c, s = 0;
    cin >> P;
    for(int a=1; 3*a <= P; a++)
      for(int b=a; a + 2*b <= P; b++)
        { c = P - a - b;
          if (a + b > c) s++;
        }
    cout << s << endl;
    return 0;
}
    
