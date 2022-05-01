#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N; cin >> N;
		for(int i = 0; i < 30; ++i) cout << (1<<i) << ' ';
		vector<int> ans;
		ll a = 0, b = 0;
		for(int i = 30; i < N; ++i) {
			int x = (1<<29)+i;
			cout << x << ' ';
			if(a < b) {
				ans.push_back(x);
				a += x;
			} else b += x;
		}
		cout << endl;
		for(int i = 0; i < N; ++i) {
			int x; cin >> x;
			if(a < b) {
				ans.push_back(x);
				a += x;
			} else b += x;
		}
		for(int i = 29; i >= 0; --i) {
			int x = 1<<i;
			if(a < b) {
				ans.push_back(x);
				a += x;
			} else b += x;
		}
		for(int x : ans) cout << x << ' ';
		cout << endl;
	}

	return 0;
}