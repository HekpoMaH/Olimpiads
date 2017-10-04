#include <iostream>

using namespace std;

string ebavamse(int num) {
   if(num==0){
      return "zero";
   }
   if (num == 100) {
     return "one hundred";
   }

   const string mrazqtiq[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
   if (10 <= num && num <= 19) {
     return mrazqtiq[num - 10];
   }

   const string ebisa[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
   const string ebisa2[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
   if (num < 10) {
     return ebisa[num - 1];
   }
   else if (num % 10 == 0) {
     return ebisa2[num / 10 - 2];
   }
   else {
     return ebisa2[num / 10 - 2] + "-" + ebisa[num % 10 - 1];
   }
}

int main() {
   int n;
   cin>>n;
   cout << ebavamse(n) << endl;
}
