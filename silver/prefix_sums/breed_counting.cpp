#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

int main() {
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vl a(n);
    for (ll &x : a) cin >> x;
    
    vector<vl> prefix_count(4, vl(n + 1, 0)); // Using 1-based indexing for simplicity

    // Calculate the prefix counts for each breed
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 3; ++j) {
            prefix_count[j][i + 1] = prefix_count[j][i] + (a[i] == j ? 1 : 0);
        }
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        // Calculate the count of each breed within the specified interval [l, r]
        vl breed_count(4);
        for (int j = 1; j <= 3; ++j) {
            breed_count[j] = prefix_count[j][r] - prefix_count[j][l - 1];
        }

        cout << breed_count[1] << " " << breed_count[2] << " " << breed_count[3] << '\n';
    }

    return 0;
}
