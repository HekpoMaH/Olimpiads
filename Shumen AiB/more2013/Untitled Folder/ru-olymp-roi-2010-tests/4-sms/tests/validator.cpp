#include "testlib.h"

#include <string>
#include <set>

using namespace std;

int main()
{
    registerValidation();

    set<string> used;
    string s = inf.readToken("[0-9]{10}");
    assert(used.insert(s).second);
    inf.readEoln();
    string t = inf.readToken("[0-9]{10}");
    inf.readEoln();
    assert(used.insert(t).second);

    for (int i = 0; i < 5; ++i) {
      int n = inf.readInt(1, 100000);
      inf.readEoln();
      for (int j = 0; j < n; ++j) {
        string t = inf.readToken("[0-9]{10}");
        inf.readEoln();
        assert(used.insert(t).second);
      }
    }
    inf.readEof();

    return 0;
}
