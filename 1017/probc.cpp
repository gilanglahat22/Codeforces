#include <bits/stdc++.h>
using namespace std;

int t;

void solve() {
    int n; cin >> n;
    vector<vector<int> > g(n, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> g[i][j];
        }
    }

    int max_num = 2*n;
    vector<bool> pres(max_num + 1, false);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            pres[g[i][j]] = true;
        }
    }

    int p1=-1;
    for(int i = 1; i<=max_num; i++){
        if(!pres[i]){
            p1=i;
            break;
        }
    }

    vector<int> p(2*n + 1);
    p[1] = p1;
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n; j++){
            p[(i+1) + (j+1)] = g[i][j];
        }
    }

    for(int i = 1; i<=2*n; i++){
        cout << p[i] << " ";
    }
    cout << "\n";
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