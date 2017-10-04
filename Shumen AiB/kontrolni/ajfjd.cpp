#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> filters;
unordered_map<string, int>::iterator it;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);

    int n, k, subtask;

    cin >> n >> subtask;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        filters[s]++;
    }

    cin >> k;
    vector<string> hosts;
    vector<string> paths;
   for (int i = 0; i < k; i++) {
        cin >> s;
        string host;
        string path;
        int index = s.find_first_of('/');
        if (index >= 0) {
            host = s.substr(0, index);
            path = s.substr(index);
        } else {
            host = s;
            path = "";
        }

        hosts.clear();
        hosts.push_back(host);
        host = "*." + host;
        index = host.find_first_of('.');
        while (index >= 0) {                
            hosts.push_back("*" + host.substr(index));
            index = host.find_first_of('.', index + 1);
        }

        paths.clear();
        paths.push_back(path);
        path = path + "/*";
        index = path.find_last_of('/');
        while (index >= 0) {
            paths.push_back(path.substr(0, index + 1) + "*");
            if (!index) break;
            index = path.find_last_of('/', index - 1);
        }            

        int a = 0;
        for (int i = 0; i < hosts.size(); i++)
            for (int j = 0; j < paths.size(); j++){
                it = filters.find(hosts[i]+paths[j]);
                if (it != filters.end()) {
                    a += it->second;
                }
            }
        cout << a << "\n";
   }
}
