#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

/*
WLOG suppose num 0s == num 1s or num 0s == num 1s + 1
From n we get the number of 0s and the number of 1s

How should we construct exactly k pairs?
k == 0 just alternate
k == 1 0 0, alternate on both sides i.e. 1 0 0 1
k == 2 00 11, alternate on both sides
k == 3 000 11, alternate on both sides
*/
void solve() {
    int n, k;
    cin >> n >> k;
    int n0 = n / 2 + n % 2;
    int n1 = n / 2;

    string s;
    if (k == 0) {
        for (int i = 0; i < n; ++i) {
            s += to_string(i%2);
        }
    } else if (k == 1) {
        if (n < 3) {
            cout << -1 << "\n";
            return;
        }
        s += "100";
        for (int i = 0; i < n - 3; ++i) {
            s += to_string(1 - i % 2);
        }
    } else {
        // k >= 2
        // alternate 00...11.... alternate
        // if k even, then 0 string k/2+1, 1 string k/2+1
        // else 0 string k/2+2, 1 string k/2+1
        int run0 = k / 2 + 1 + k % 2;
        int run1 = k / 2 + 1;
        int rem0 = n0 - run0;
        int rem1 = n1 - run1;
        if (rem0 < 0 || rem1 < 0) {
            cout << -1 << "\n";
            return;
        }
        for (int i = 0; i < run0; ++i) {
            s += "0";
        }
        for (int i = 0; i < run1; ++i) {
            s += "1";
        }
        if (rem0 >= rem1) {
            for (int i = 0; i < rem0 + rem1; ++i) {
                s += to_string(i % 2);
            }
        } else {
            string prepend;
            for (int i = 0; i < rem0 + rem1; ++i) {
                prepend += to_string(1 - i % 2);
            }
            reverse(prepend.begin(), prepend.end());
            s = prepend + s;
        }
    }
    cout << s << "\n";
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