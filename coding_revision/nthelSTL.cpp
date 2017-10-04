#include <iostream>     // std::cout
#include <algorithm>    // std::nth_element, std::random_shuffle
#include <vector>       // std::vector
using namespace std;
bool myfunction (int i,int j) { return (i<j); }

int main () {
  vector<int> myvector;

  // set some values:
  for (int i=1; i<10; i++) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9

 random_shuffle (myvector.begin(), myvector.end());
  for(int i=0;i<9;i++)cout<<myvector[i]<<" ";cout<<endl;
  // using default comparison (operator <):
  nth_element (myvector.begin(), myvector.begin()+3, myvector.begin()+4);
  // using function as comp
  //std::nth_element (myvector.begin(), myvector.begin()+5, myvector.end(),myfunction);
 // nth_element (myvector.begin(), myvector.end(), myvector.end());
for(int i=0;i<9;i++)cout<<myvector[i]<<" ";cout<<endl;
  return 0;
}
//0889535348
