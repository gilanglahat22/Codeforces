#include <bits/stdc++.h>
using namespace std;

int t;

void solve() {
    string p, s;
    cin >> p >> s;
    
    vector<pair<char, int> > groups_p, groups_s;
    
    if (p.empty()) {
        cout << (s.empty() ? "YES\n" : "NO\n");
        return;
    }
    char prev = p[0];
    int count = 1;
    for (int i = 1; i < p.size(); ++i) {
        if (p[i] == prev) {
            ++count;
        } else {
            groups_p.emplace_back(prev, count);
            prev = p[i];
            count = 1;
        }
    }
    groups_p.emplace_back(prev, count);
    
    if (s.empty()) {
        cout << "NO\n";
        return;
    }
    prev = s[0];
    count = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == prev) {
            ++count;
        } else {
            groups_s.emplace_back(prev, count);
            prev = s[i];
            count = 1;
        }
    }
    groups_s.emplace_back(prev, count);
    
    if (groups_p.size() != groups_s.size()) {
        cout << "NO\n";
        return;
    }
    
    for (int i = 0; i < groups_p.size(); ++i) {
        if (groups_p[i].first != groups_s[i].first) {
            cout << "NO\n";
            return;
        }
        int cnt_p = groups_p[i].second;
        int cnt_s = groups_s[i].second;
        if (cnt_s < cnt_p || cnt_s > 2 * cnt_p) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}