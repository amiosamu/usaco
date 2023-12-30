#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	
	int N;
	cin >> N;
	
	vector<int> cows(N);
	vector<int> prefix(N+1);
	
	for (int i = 0; i < N; i++){
		cin >> cows[i];
		prefix[i+1] = (prefix[i] + cows[i]) % 7;
	}
	vector<int> v(7);
	for (int i = 0; i < 7; i++){
		v[i] = -1;
	}
	int maximum = 0;
	
	for (int i = 0; i < prefix.size(); i++){
		if (v[prefix[i]] == -1){
			v[prefix[i]] = i;
		}
		else {
			maximum = max(i - v[prefix[i]],maximum);
		}
	}
	cout << maximum << '\n';
}