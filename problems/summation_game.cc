#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < x; ++i) {
        a[a.size()-1-i] *= -1;
    }

    ll sum = 0;
    for (auto& i : a) {
        sum += i;
    }
    ll maxsofar = sum;

    for (int i = 0; i < k; ++i) {
        int size = a.size();
        if (size-x <= 0 && a.size()) {
            sum += -1*a[a.size()-1];
            a.pop_back();
            maxsofar = max(maxsofar, sum);
            continue;
        }

        if (!a.size()) {
            break;
        }

        sum += -1*a[a.size()-1] - 2*a[a.size()-1-x];
        a[a.size()-1-x] *= -1;
        a.pop_back();
        maxsofar = max(maxsofar, sum);
    }

    cout << maxsofar << endl;
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