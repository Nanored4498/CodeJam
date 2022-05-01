#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N; cin >> N;
		vector<int> D(N);
		for(int &x : D) cin >> x;
		int ans = 0, last = 0;
		for(int i = 0, j = N-1; i <= j;) {
			if(min(D[i], D[j]) >= last) {
				++ ans;
				last = min(D[i], D[j]);
			}
			if(D[i] < D[j]) ++i;
			else --j;
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}