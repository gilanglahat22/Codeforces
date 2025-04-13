#include <bits/stdc++.h>
using namespace std;

int t;

void solve() {
    int n;
    cin >> n;
    
    if (n == 2 || n == 4) {
        cout << "-1" << endl;
        return;
    }
    
    if (n == 3) {
        cout << "3 1 2" << endl;
        return;
    }
    
    if (n == 5) {
        cout << "1 5 2 3 4" << endl;
        return;
    }
    
    if (n % 2 == 1) {
        // For odd n >= 7
        cout << n << " ";
        for (int i = 1; i < n; i++) {
            cout << i << (i == n-1 ? "\n" : " ");
        }
    } else {
        cout << "-1" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> t;
    while(t--){
        solve();
    }
    return 0;
}