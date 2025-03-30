#include <bits/stdc++.h>
using namespace std;
 
char getThirdChar(char a, char b) {
    if ((a == 'L' && b == 'I') || (a == 'I' && b == 'L')) return 'T';
    if ((a == 'L' && b == 'T') || (a == 'T' && b == 'L')) return 'I';
    if ((a == 'I' && b == 'T') || (a == 'T' && b == 'I')) return 'L';
    return 'X'; 
}
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int countL = 0, countI = 0, countT = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == 'L') countL++;
        else if (c == 'I') countI++;
        else if (c == 'T') countT++;
    }
    
    if (countL == countI && countI == countT) {
        cout << 0 << endl;
        return;
    }
    
    if (n == 1) {
        cout << -1 << endl;
        return;
    }
    
    vector<int> operations;
    string current = s;
    
    while (operations.size() < 2 * n) {
        // Recalculate character counts
        int currL = 0, currI = 0, currT = 0;
        for (int i = 0; i < current.length(); i++) {
            char c = current[i];
            if (c == 'L') currL++;
            else if (c == 'I') currI++;
            else if (c == 'T') currT++;
        }
        
        if (currL == currI && currI == currT) {
            break;
        }
        
        char toInsert;
        if (currL <= currI && currL <= currT) toInsert = 'L';
        else if (currI <= currL && currI <= currT) toInsert = 'I';
        else toInsert = 'T';
        
        bool inserted = false;
        
        for (int i = 0; i < current.size() - 1; i++) {
            if (current[i] != current[i+1] && 
                toInsert != current[i] && 
                toInsert != current[i+1]) {
                
                operations.push_back(i + 1);
                current.insert(current.begin() + i + 1, toInsert);
                inserted = true;
                break;
            }
        }
        
        if (!inserted) {
            for (int i = 0; i < current.size() - 1; i++) {
                if (current[i] != current[i+1]) {
                    char third = getThirdChar(current[i], current[i+1]);
                    
                    operations.push_back(i + 1);
                    current.insert(current.begin() + i + 1, third);
                    inserted = true;
                    break;
                }
            }
        }
 
        if (!inserted) {
            cout << -1 << endl;
            return;
        }
    }
    
    int finalL = 0, finalI = 0, finalT = 0;
    for (int i = 0; i < current.length(); i++) {
        char c = current[i];
        if (c == 'L') finalL++;
        else if (c == 'I') finalI++;
        else if (c == 'T') finalT++;
    }
    
    if (finalL != finalI || finalI != finalT) {
        cout << -1 << endl;
        return;
    }
    
    cout << operations.size() << endl;
    for (int i = 0; i < operations.size(); i++) {
        cout << operations[i] << endl;
    }
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