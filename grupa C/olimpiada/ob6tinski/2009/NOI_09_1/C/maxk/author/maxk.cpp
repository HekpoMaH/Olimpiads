#include <iostream>

using namespace std;

int main()
{
    int N, K, a[1000];
    cin>> N >> K;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    
    int maxx = a[0], sum; 
    for (int i = 0; i <= N - K; i++)
    { 
        sum = 0;
        for (int j = i; j < i + K; j++)
            sum += a[j];
        if (sum>=maxx) maxx=sum;
    }
    
    cout << maxx <<endl;
    cin >> N;
}
