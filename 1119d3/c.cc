#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

/*
When would you ever replace with a 1?
Doesn't make sense to replace a -1 between 1s with a 1
Case: 1+ ones
    - Replace first -1 before, last -1 after all
Case: 0 ones
    - Replace first and last -1
*/
void solve() {
    int n;
    cin >> n;
    vt<int> arr(n);
    for (auto& a : arr) cin >> a;

    vt<int> idx1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 1) {
            idx1.push_back(i);
        }
    }

    if (idx1.size() == 0) {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == -1) {
                arr[i] = 1;
                break;
            }
        }
        for (int i = n-1; i >= 0; --i) {
            if (arr[i] == -1) {
                arr[i] = 1;
                break;
            }
        }
        for (auto& a : arr) {
            if (a == -1) {
                a = 0;
            }
        }

        for (auto a : arr) cout << a << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < idx1.front(); ++i) {
        if (arr[i] == -1) {
            arr[i] = 1;
            break;
        }
    }
    for (int i = n-1; i > idx1.back(); --i) {
        if (arr[i] == -1) {
            arr[i] = 1;
            break;
        }
    }
    for (auto& a : arr) {
        if (a == -1) {
            a = 0;
        }
    }

    for (auto a : arr) cout << a << " ";
    cout << "\n";
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