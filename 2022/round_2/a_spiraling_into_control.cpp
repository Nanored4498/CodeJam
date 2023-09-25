#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int N, K;
		cin >> N >> K;
		int r = N*N-1-K;
		int mo = 0, i = 2, a = N, b = 4*N-6;
		vector<pii> ans;
		while(r && a>1) {
			if(b <= r) {
				ans.emplace_back(i, i+b+1);
				r -= b;
				i = i+b+2;
				a -= 2;
				b -= 8;
			} else {
				i += a-1;
				b -= 2;
				if(mo == 3) {
					mo = 0;
					a -= 2;
				} else ++mo;
			}
		}
		if(r) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << ans.size() << '\n';
			for(auto [i, j] : ans) cout << i << ' ' << j << '\n';
		}
	}

	return 0;
}