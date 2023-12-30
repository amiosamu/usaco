#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("diamond.in", "r", stdin);
	int n, k;
	cin >> n >> k;
	vector<int> diamonds(n);
	for (int &d : diamonds) { cin >> d; }

	int most = 0;
	/*
	 * Iterate through all diamonds and test setting them
	 * as the smallest diamond in the case.
	 */
	for (int x : diamonds) {
		int fittable = 0;
		/*
		 * Get all diamonds at least as large as x (including x itself)
		 * that differ from it by no more than k.
		 */
		for (int y : diamonds) {
			if (x <= y && y <= x + k) { fittable++; }
		}
		most = max(most, fittable);
	}

	freopen("diamond.out", "w", stdout);
	cout << most << endl;
}
