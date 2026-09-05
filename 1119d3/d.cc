#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

/*
WLOG let MEX(A) be the largest. 
Then, we want MEX(B) + MEX(C) >= MEX(A). 
*/
void solve() {
    int n;
    cin >> n;
    vt<int> arr(n);
    for (auto& a : arr) cin >> a;

    int cnt0 = 0;
    for (auto a : arr) {
        if (a == 0) {
            cnt0++;
        }
    }

    if (cnt0 == 0) {
        string ans = "";
        for (auto a : arr) ans += "A";
        cout << "YES" << "\n";
        cout << ans << "\n";
    } else if (cnt0 == 1) {
        cout << "NO" << "\n";
    } else {
        string ans = "";
        cout << "YES" << "\n";
        bool foundA = false;
        for (auto a : arr) {
            if (a != 0) {
                ans += "C";
            } else {
                if (!foundA) {
                    ans += "A";
                    foundA = true;
                } else {
                    ans += "B";
                }
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}