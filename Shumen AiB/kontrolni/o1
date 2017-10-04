#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

const int MAX_STATE = 4 * 1024 * 1024 + 5;

int trie[MAX_STATE][27];
bool term[MAX_STATE];
int fre = 1;

int add_filter(string &s) {
    int cur = 0;
    size_t si = s.size();
    for (size_t i = 0; i < si; i++) {
        if (s[i] != '.' && s[i] != '/') {
            if (trie[cur][s[i] - 'a'] != 0) 
                cur = trie[cur][s[i] - 'a'];
            else 
                trie[cur][s[i] - 'a'] = fre, cur = fre++;
        }
        else {
            if (trie[cur][26] != 0) 
                cur = trie[cur][26];
            else 
                trie[cur][26] = fre, cur = fre++;
            term[cur] = true;
        }
    }
    term[cur] = true;
    return cur;
}

map<pair<int, int>, int> filters[2][2];

vector<int> find(string &s) {
    int cur = 0;
    vector<int> ans(1);
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] != '.' && s[i] != '/') {
            if (trie[cur][s[i] - 'a'] == 0) {
                ans.push_back(-1);
                return ans;
            } else cur = trie[cur][s[i] - 'a'];
        }
        else {
            if (term[cur]) ans.push_back(cur);
            if (trie[cur][26] == 0) {
                ans.push_back(-1);
                return ans;
            } else cur = trie[cur][26];
        }
    }
    if (term[cur]) {
        if (cur != 0) ans.push_back(cur);
    }
    else ans.push_back(-1);
    return ans;
}

pair<string, string> prepare1(string &s) {
    bool f = true;
    pair<string, string> ans;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '/' && f) {
            f = false;
            continue;
        }
        if (f) ans.first += s[i];
        else ans.second += s[i];
    }
    return ans;
}

int main() {
    ifstream cin("search.in");
    ofstream cout("search.out");

    term[0] = true;
    int n, k, subtask;
    cin >> n >> subtask;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        pair<string, string> pref_suff = prepare1(s);
        string pref = pref_suff.first, suff = pref_suff.second;
        reverse(pref.begin(), pref.end());
        bool pref_star = false, suff_star = false;
        if (pref[pref.length() - 1] == '*') {
            pref_star = true;
            pref = pref.substr(0, pref.length() - 2);
        }
        if (suff.length() > 0 && suff[suff.length() - 1] == '*') {
            suff_star = true;
            if (suff.length() > 1) 
                suff = suff.substr(0, suff.length() - 2);
            else 
                suff = "";
        }
        pair<int, int> fil = make_pair(add_filter(pref), add_filter(suff));
        if (filters[pref_star][suff_star].count(fil)) 
            filters[pref_star][suff_star][fil] += 1;
        else 
            filters[pref_star][suff_star][fil] = 1;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        pair<string, string> pref_suff = prepare1(s);
        string pref = pref_suff.first, suff = pref_suff.second;
        reverse(pref.begin(), pref.end());
        vector<int> pr = find(pref);
        vector<int> su = find(suff);
        int ans = 0;
        if (pr.size() == 0 || su.size() == 0)
            continue;

        // equal / equal
        pair<int, int> cond = make_pair(pr.back(), su.back());
        if (filters[0][0].count(cond)) ans += filters[0][0][cond];

        // equal / star
        for (size_t j = 0; j < su.size(); j++) {
            cond = make_pair(pr.back(), su[j]);
            if (filters[0][1].count(cond)) ans += filters[0][1][cond];
        }
        // star / equal
        for (size_t i = 0; i < pr.size(); i++) {
            cond = make_pair(pr[i], su.back());
            if (filters[1][0].count(cond)) ans += filters[1][0][cond];
        }

        // star / star
        for (size_t i = 0; i < pr.size(); i++)
            for (size_t j = 0; j < su.size(); j++) {
                cond = make_pair(pr[i], su[j]);
                if (filters[1][1].count(cond)) ans += filters[1][1][cond];
            }
        cout << ans << "\n";
    }
}
