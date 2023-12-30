#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)size(x)

using ll = long long;
using vl = vector<ll>;

vl psum(const vl &a){
	vl psum(sz(a) + 1);
	for (int i = 0; i < sz(a); ++i){
		psum[i+1] = psum[i] + a[i];
	}
	return psum;
}

int main(){
	int n, q;
	cin >> n >> q;
	vl a(n);
	for (ll &x : a) cin >> x;
	vl p = psum(a);
	for (int i = 0; i < q; ++i){
		int l, r;
		cin >> l >> r;
		cout << p[r] - p[l] << '\n';
	}
	return 0;
}