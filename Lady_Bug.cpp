#include <bits/stdc++.h>
using namespace std;
 
class DisjointSet {
private:
    vector<int> parent, rank;
    
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        
        if (root_x == root_y) return;
        
        if (rank[root_x] < rank[root_y]) {
            parent[root_x] = root_y;
        } else if (rank[root_x] > rank[root_y]) {
            parent[root_y] = root_x;
        } else {
            parent[root_y] = root_x;
            rank[root_x]++;
        }
    }
};
 
void solve() {
    int n;
    cin >> n;
    
    string a, b;
    cin >> a >> b;
    
    DisjointSet ds(2 * n);
    
    // Connect positions based on the allowed swaps
    for (int i = 1; i < n; i++) {
        ds.unite(i, n + i - 1);       // a[i] can swap with b[i-1]
        ds.unite(n + i, i - 1);       // b[i] can swap with a[i-1]
    }
    
    // Group positions by their connected components
    vector<vector<int> > components(2 * n);
    for (int i = 0; i < n; i++) {
        int root_a = ds.find(i);
        components[root_a].push_back(i);
        
        int root_b = ds.find(n + i);
        components[root_b].push_back(n + i);
    }
    
    // For each connected component, check if we can make all a positions 0
    for (int i = 0; i < 2 * n; i++) {
        if (components[i].empty()) continue;
        
        int ones_count = 0;
        int a_positions_count = 0;
        int b_positions_count = 0;
        
        for (int j = 0; j < components[i].size(); j++) {
            int pos = components[i][j];
            if (pos < n) {  // Position in string a
                a_positions_count++;
                if (a[pos] == '1') ones_count++;
            } else {        // Position in string b
                b_positions_count++;
                if (b[pos - n] == '1') ones_count++;
            }
        }
        
        if (ones_count > b_positions_count) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
