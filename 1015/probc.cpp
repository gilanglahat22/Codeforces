#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

typedef pair<int, int> pii;

bool validate(int n, vector<pii>& pairs) {
    vector<pii> sorted = pairs;
    for (vector<pii>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
        if (it->first > it->second) swap(it->first, it->second);
    }
    
    sort(sorted.begin(), sorted.end());
    
    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            if (i+1 >= n || sorted[i] != sorted[i+1]) return false;
        }
    } else {
        bool found_center = false;
        int i = 0;
        while (i < n) {
            if (i+1 < n && sorted[i] == sorted[i+1]) {
                i += 2;
            } else {
                if (found_center || sorted[i].first != sorted[i].second) return false;
                found_center = true;
                i += 1;
            }
        }
    }
    return true;
}

vector<pii> generate_swaps(vector<int>& perm);

vector<pii> solve(vector<pii>& pairs, int n) {
    map<int, vector<int> > pos_map;
    for (int i = 0; i < n; ++i) {
        int key = pairs[i].first * 1000000 + pairs[i].second;
        pos_map[key].push_back(i);
    }
    
    vector<int> perm(n, -1);
    vector<bool> used(n, false);
    
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        
        int target_val = n - 1 - i;
        pii target_pair = make_pair(pairs[target_val].second, pairs[target_val].first);
        
        int key = target_pair.first * 1000000 + target_pair.second;
        if (pos_map[key].empty()) return vector<pii>();
        
        int j = pos_map[key].back();
        pos_map[key].pop_back();
        
        perm[i] = j;
        perm[j] = i;
        used[i] = used[j] = true;
    }
    
    return generate_swaps(perm);
}

vector<pii> generate_swaps(vector<int>& perm) {
    int n = perm.size();
    vector<bool> visited(n, false);
    vector<pii> swaps;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && perm[i] != i) {
            vector<int> cycle;
            int j = i;
            while (!visited[j]) {
                cycle.push_back(j);
                visited[j] = true;
                j = perm[j];
            }
            for (int k = cycle.size()-1; k > 0; --k) {
                swaps.push_back(make_pair(cycle[k-1]+1, cycle[k]+1));
            }
        }
    }
    return swaps;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        
        vector<pii> pairs;
        for (int i = 0; i < n; ++i) {
            pairs.push_back(make_pair(a[i], b[i]));
        }
        
        if (!validate(n, pairs)) {
            cout << "-1\n";
            continue;
        }
        
        vector<pii> swaps = solve(pairs, n);
        if (swaps.empty()) {
            cout << "-1\n";
        } else {
            cout << swaps.size() << '\n';
            for (size_t i = 0; i < swaps.size(); ++i) {
                cout << swaps[i].first << " " << swaps[i].second << '\n';
            }
        }
    }
    return 0;
}