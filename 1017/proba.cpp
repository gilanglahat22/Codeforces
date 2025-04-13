#include <bits/stdc++.h>
using namespace std;

int t;

void solve() {
    string s;
    getline(cin >> ws, s);
    int sz = s.size();
    bool flag = false;
    string ans = "";
    ans+=s[0];
    for(int i = 0; i<sz; i++){
        if(!flag){
            if(s[i]==' '){
                flag = true;
            }
        }else{
            if(s[i]!=' '){
                flag = false;
                ans += s[i];
            }
        }
    }

    cout << ans << "\n";
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