#include <iostream>
using namespace std;

void sort(int a[], int n)
{
         int t; 
         for(int i = 1; i < n; i++)
                 for(int j = i; j > 0; j--)
                         if(a[j] > a[j - 1])
                         {
                                 t = a[j];
                                 a[j] = a[j - 1];
                                 a[j-1] = t;
                         }
                         else
                             break;
}

int main()
{
    int S, N, min = 0;
    cin >> S >> N;
    int prices[3000];
    for(int i = 0; i < N; i++)
            cin >> prices[i];
    sort(prices, N);
    while(S > 0)
    {
            for(int i = 0; i < N; i++)
                    if(S >= prices[i])
                    {
                         S = S - prices[i];
                         min++;
                         break;
                    }
    }
    cout << min << endl;
    system("pause");
    return 0;
}
