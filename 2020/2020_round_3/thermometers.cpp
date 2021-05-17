#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int K, N, temp;
		cin >> K >> N;
		vi X(N);
		for(int i = 0; i < N; ++i) cin >> X[i];
		for(int i = 0; i < N; ++i) cin >> temp;

		vi S(N), L(N);
		for(int i = 0; i+1 < N; ++i) S[i] = X[i+1] - X[i];
		S[N-1] = K + X[0] - X[N-1];
		bool opt = false;
		for(int i = 0; i < N; ++i) {
			L[i] = 1;
			int ps = S[(i+N-1)%N];
			int a = 0, b = min(ps, S[i]);
			int s = S[i];
			while(L[i] < N) {
				int ns = S[(i+L[i])%N];
				if(L[i]&1) {
					s -= ns;
					a = max(a, s);
				} else {
					s += ns;
					b = min(b, s);
				}
				if(a < b) ++ L[i];
				else break;
			}
			if(L[i] == N) {
				if(N&1) {
					if(2*a < s && s < 2*b) opt=true;
				} else if(s == 0) opt = true;
			}
		}

		int ans = opt ? N : 2*N;
		for(int i = 0; i < N; ++i) {
			int step = 0;
			int l = 0;
			while(l < N) {
				++ step;
				l += L[(i+l)%N];
			}
			ans = min(ans, N+step);
		}

		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}