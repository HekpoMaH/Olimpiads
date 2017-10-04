#include <iostream>
using namespace std;
int main()
{
    int N, a, b;
    cin>>N;
    a=1;
    b=1;

    while (N-1>a-b && a<N && b<N)
    {
          b++;
          
          if (N%b==0) a=N/b; 
          if (b-a<=0) break;
    }
    cout<<a<<" "<<b;
    return 0;
}
