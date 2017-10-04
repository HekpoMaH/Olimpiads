#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    map<string, int> freq; // map of words and their frequencies
    string word;           // input buffer for words.
    //--- Read words/tokens from input stream
    while (cin >> word) { freq[word]++;     }
    //--- Write the count and the word.
    map<string, int>::iterator iter;
    for (iter=freq.begin(); iter != freq.end(); ++iter) {
        cout << iter->second << " " << iter->first << endl;
    }
    return 0;
}//end main
