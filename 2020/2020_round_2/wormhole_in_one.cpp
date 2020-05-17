#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;	

int T, N, x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for(int tt = 1; tt <= T; ++tt) {
		cin >> N;
		vii ps(N);
		for(int i = 0; i < N; ++i) cin >> ps[i].first >> ps[i].second;

		map<pii, set<int>> co;
		int res = 0;
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < i; ++j) {
				pii v = {ps[i].first - ps[j].first, ps[i].second - ps[j].second};
				if(v.first == 0) v.second = 1;
				else {
					int g = __gcd(abs(v.first), abs(v.second));
					if(v.first < 0) g = -g;
					v.first /= g;
					v.second /= g;
				}
				co[v].emplace(i);
				co[v].emplace(j);
				res = max(res, (int) co[v].size());
			}
		}
		if(res % 2 == 0) res = min(N, res+2);
		else res = min(N, res+1);

		cout << "Case #" << tt << ": " << res << "\n";
	}

	return 0;
}