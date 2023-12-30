#include <bits/stdc++.h>
using namespace std;


int main(){
    //freopen("shuffle.in", "r", stdin);
    //freopen("shuffle.out", "w", stdout);
    int n; cin >> n;
	vector<int> shuffle(n);
	for (int &i : shuffle) { cin >> i; }
	vector<int> ids(n);
	for (int &i : ids) { cin >> i; }
	for (int i = 0; i < 3; i++) {
		vector<int> past_order(n);
		for (int j = 0; j < n; j++) {
			// -1 because the shuffle input starts from 1
			past_order[j] = ids[shuffle[j] - 1];
		}
		ids = past_order;
	}
    for (const int &i : ids) {
        cout << i << '\n';
    }
}
