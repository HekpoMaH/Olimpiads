#include <iostream>
#include <list>
using namespace std;

// poddurjame spisuk ot prosti 4isla,
// tui-kato za da se proveri dali dadeno 4islo e prosto
// trqbva da obhodime spisuka.
list<int> primes;
int array[50000];
int r_ways[50000];

bool is_prime(int this_prime)
{ 
 if (this_prime == 1)
    return false;
 if (array[this_prime])
  return true;
 int number = this_prime%6;
 if ((number!=1) && ((this_prime+1)%6))
    return false;
 for (list<int>::iterator it=primes.begin(); it!=primes.end(); it++)
 {
  if (!(this_prime)%*it)
  {
     return false;
  }
 }
 primes.push_back(this_prime);
 if (!array[this_prime])
 array[this_prime] = 1;
 return true;
}

int S(int n)
{
    if (n == 2)
       return 1;
    if (n == 3)
       return 1;
    int ways=0;

    for (int k=2; k<n; k++)
    {
        if (is_prime(k))
           ways = ways + k;
    }
    ways = ways-n;
    if (!is_prime(ways))
     ways = ways/2 - (ways%2);
    else
     ways = ways-1;
    if (!ways)
       ways = 1;
    return ways;
}

int main()
{
    primes.push_back(2);
    primes.push_back(3);
    array[2] = 1;
    array[3] = 1;
    for (int c=0; c<50000; c++)
        r_ways[c] = -1;
    int n;
    cin >> n;
    long long int k=n+1;
    // namirame sledva6toto prosto 4islo
    while (!is_prime(k))
          k++;
    long long int ways = S(n);
    cout << ways%k << endl;
    while(cin);
    return 0;
}
