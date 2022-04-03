#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	int T;
	cin >> T;
	mt19937 mt(42);
	for(int t = 1; t <= T; ++t) {
		int N, K; cin >> N >> K;
		K = min(K, N-1);
		vi seen(N, 0), ps(N, 0);
		int r; cin >> r >> ps[--r];
		ll ans = ps[r];
		vi order(N);
		iota(order.begin(), order.end(), 0);
		shuffle(order.begin(), order.end(), mt);
		for(int k = 0, l = 0; k < K-1; k+=2) {
			cout << "W" << endl;
			cin >> r >> ps[--r];
			++ seen[r];
			while(seen[order[l]]) ++l;
			cout << "T " << order[l++]+1 << endl;
			cin >> r >> ps[--r];
			ans += ps[r];
		}
		sort(order.begin(), order.end(), [&](int i, int j) { return seen[i]>seen[j]; });
		if(seen[order[0]]*N > 100*K) ans = (ps[order[0]]*((K-1)/2))/seen[order[0]];
		else ans = (ans*N)/(1+(K-1)/2)/2;
		cout << "E " << ans << endl;
	}

	return 0;
}