#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

// Set of primes
const int MAX = 1000001;
bool prime[MAX];
void sieve ()
{
    int i,j;
    prime[0] = prime[1] = true;

    for (i=4; i<MAX; i+=2)
        prime[i] = true;

    for (i=3; i*i<=MAX; i+=2)
        if (!prime[i])
            for (j=i*i; j<MAX; j+=2*i)
                prime[j] = true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sieve();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        ll x;
        cin >> x;
        ll candidate = sqrt(x);
        if (!prime[candidate] && candidate * candidate == x) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}