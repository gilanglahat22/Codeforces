#include <bits/stdc++.h>
using namespace std;

int t;
int n,m,l,r;
void solve() {
    cin >> n >> m >> l >> r;
    int lower = max(l, -m);
    int upper = min(l+(n-m), 0);
    int next_l = (2 * l + n - m)/2;
    int l_prime = max(lower, min(upper, next_l));
    int r_prime = m + l_prime;
    cout << l_prime << " " << r_prime << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    cin.ignore();
    while(t--){
        solve();
    }
    return 0;
}