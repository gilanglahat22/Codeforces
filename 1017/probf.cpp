#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> grid(n, vector<int>(m, 0));
    
    int target_count = (n * m) / k;
    vector<int> counts(k + 1, 0);
    
    if (k == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = ((i + j) % 2) + 1;
            }
        }
    } else if (k >= 4 && k == n * m) {
        int num = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = num++;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<bool> valid(k + 1, true);
                
                if (i > 0) valid[grid[i-1][j]] = false;
                if (j > 0) valid[grid[i][j-1]] = false;
                
                bool assigned = false;
                for (int num = 1; num <= k; num++) {
                    if (valid[num] && counts[num] < target_count) {
                        grid[i][j] = num;
                        counts[num]++;
                        assigned = true;
                        break;
                    }
                }
                
                if (!assigned) {
                    for (int num = 1; num <= k; num++) {
                        if (valid[num]) {
                            grid[i][j] = num;
                            counts[num]++;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << (j < m - 1 ? " " : "");
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}