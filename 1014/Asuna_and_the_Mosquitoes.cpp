#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    
    vector<int> heights(n);
    long long total_sum = 0;
    int max_height = 0;
    int odd_count = 0;
    bool has_odd = false;
    bool has_even = false;
    
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
        total_sum += heights[i];
        max_height = max(max_height, heights[i]);
        
        if (heights[i] % 2 == 1) {
            odd_count++;
            has_odd = true;
        } else {
            has_even = true;
        }
    }
    
    if (!(has_odd && has_even)) {
        cout << max_height << endl;
        return;
    }
    
    long long max_beauty = total_sum - odd_count + 1;
    cout << max_beauty << endl;
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