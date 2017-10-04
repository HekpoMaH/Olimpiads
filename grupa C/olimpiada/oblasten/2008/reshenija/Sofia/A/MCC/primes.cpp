#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<unsigned> primes;
vector<vector<unsigned> > poss;

bool prime(unsigned);
void generatePrimes(unsigned);
long vectorSum(vector<unsigned>);
int  enumPoss(unsigned,vector<unsigned>);
void output(vector<unsigned>);
void sort(vector<unsigned>&);
vector<vector<unsigned> > separateUnique(vector<vector<unsigned> >&);
unsigned nextPrime(unsigned);

int main()
{
    unsigned n;
    cin >> n;
    if (n==1 || n==0)
	{
		cout << 0;
		return 0;
	}
    generatePrimes(n);
    vector<unsigned> blank;
    enumPoss(n,blank);
	poss = separateUnique(poss);
    cout << poss.size() % nextPrime(n);
    return 0;
}

void generatePrimes(unsigned n)
{
     for (unsigned i=2;i<n;i++)
         if (prime(i)) primes.push_back(i);
}

bool prime(unsigned n)
{
     for (unsigned i=2;i<=sqrt(n);i++)
         if (n%i == 0) return false;
     return true;
}

long vectorSum(vector<unsigned> vec)
{
    long sum=0;
    for (unsigned i=0;i<vec.size();i++) sum += vec[i];
    return sum;
}

int enumPoss(unsigned n, vector<unsigned> sofar)
{
     long sum = vectorSum(sofar);
     if (n == sum)
     {
	  	   sort(sofar);
           poss.push_back(sofar);
           return 0;
     }
     unsigned i=0;
     while (primes[i] <= n-sum)
     {
           sofar.push_back(primes[i]);
           enumPoss(n, sofar);
           sofar.pop_back();
           i++;
     }
}

void output(vector<unsigned> vec)
{
 	 for (unsigned i=0;i<vec.size();i++)
 	 	 cout << vec[i] << " ";
 	 cout << endl;
}

void sort(vector<unsigned>& vec)
{
 	 unsigned t;
 	 unsigned swaps=1;
 	 while (swaps != 0)
 	 {
	  	   swaps = 0;
	  	   for (unsigned i=0;i<vec.size()-1;i++)
	  	   	   if (vec[i] > vec[i+1])
	  	   	   {
			   	  		  t = vec[i];
			   	  		  vec[i] = vec[i+1];
			   	  		  vec[i+1] = t;
			   	  		  swaps++;
			   }
     }
}

vector<vector<unsigned> > separateUnique(vector<vector<unsigned> >& orig)
{
	bool equal;
	vector<vector<unsigned> > unique;
	for (unsigned o=0;o<orig.size();o++)
	{
		equal = false;
		for (unsigned u=0;u<unique.size() && !equal;u++)
			equal = (orig[o] == unique[u]);
		if (!equal)
			unique.push_back(orig[o]);
	}
	return unique;
}

unsigned nextPrime(unsigned n)
{
	unsigned x = n+1;
	while (!prime(x)) x++;
	return x;
}
