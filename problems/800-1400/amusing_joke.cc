#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;

    unordered_map<char,int> freq;
    for (auto& c : s1) {
        freq[c] += 1;
    }
    for (auto& c : s2) {
        freq[c] += 1;
    }
    for (auto& c : s3) {
        freq[c] -= 1;
    }

    bool valid = true;
    for (const auto& [key,val] : freq) {
        if (val != 0) {
            cout << "NO" << endl;
            valid = false;
            break;
        }
    }
    if (valid) cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}