#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    string s;
    cin >> s;
    // need some subsequence of integers that form an integer divisible by 8
    bool ans = false;
    int res;

    for (int i = 0; i < s.size(); ++i) {
        for (int j = i+1; j < s.size(); ++j) {
            for (int k = j+1; k < s.size(); ++k) {
               int num = 100*(s[i]-48) + 10*(s[j]-48) + s[k]-48;
               if (num % 8 == 0) {
                ans = true;
                res = num;
               }
            }
        }
    }

    for (int i = 0; i < s.size(); ++i) {
        for (int j = i+1; j < s.size(); ++j) {
            int num = 10*(s[i]-48) + s[j]-48;
            if (num % 8 == 0) {
                ans = true;
                res = num;
            }
        }
    }

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '8' || s[i] == '0') {
            ans = true;
            res = s[i]-48;
        }
    }

    if (ans) cout << "YES\n" << res << "\n";
    else cout << "NO\n";
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