#include <iostream>
#include <vector>
using namespace std;

vector<vector<unsigned> > groups;
vector<double> numbers;
vector<double> ds;

long vectorSum(vector<unsigned>);
int createGroups(unsigned,unsigned,vector<unsigned>);
void output(vector<unsigned>);
vector<vector<unsigned> > separateUnique(vector<vector<unsigned> >&);
double calcD(vector<unsigned>);

int main()
{
	double num;
	unsigned n,p;
	cin >> n >> p;
	for (unsigned i=0;i<n;i++)
	{
		cin >> num;
		numbers.push_back(num);
	}
	vector<unsigned> blank;
	createGroups(n, p, blank);
	groups = separateUnique(groups);
	for (unsigned i=0;i<groups.size();i++)
		ds.push_back(calcD(groups[i]));
	//Find min
	double min = ds[0];
	for (unsigned i=0;i<ds.size();i++)
		if (ds[i] < min) min = ds[i];
	cout << min;
}

long vectorSum(vector<unsigned> vec)
{
    long sum=0;
    for (unsigned i=0;i<vec.size();i++) sum += vec[i];
    return sum;
}

int createGroups(unsigned n, unsigned p, vector<unsigned> sofar)
{
	long sum = vectorSum(sofar);
	if (n == sum && sofar.size() == p)
	{
		groups.push_back(sofar);
		return 0;
	}
	unsigned i=1;
	while (i <= n-sum)
	{
		sofar.push_back(i);
		createGroups(n,p,sofar);
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

double calcD(vector<unsigned> group)
{
	vector<double> averages;
	double d = 0.0;
	unsigned i=0;
	unsigned end=0;
	double average;
	for (unsigned g=0;g<group.size();g++) //iterate through groups, g-group index, find averages
	{
		average = 0.0;
		end += group[g];
		for (;i<end;i++)
			average += numbers[i];
		average /= group[g];
		averages.push_back(average);
	}
	i=0;
	end=0;
	for (unsigned g=0;g<group.size();g++)
	{
		end += group[g];
		for (;i<end;i++)
			d += (numbers[i]-averages[g])*(numbers[i]-averages[g]);
	}
	return d;
}
