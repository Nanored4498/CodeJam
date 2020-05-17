#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;	

int T, C, D, x, u, v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for(int tt = 1; tt <= T; ++tt) {
		cin >> C >> D;
		vii X1, X2;
		for(int i = 2; i <= C; ++i) {
			cin >> x;
			if(x < 0) X1.emplace_back(-x, i);
			else X2.emplace_back(x, i);
		}
		sort(X1.begin(), X1.end());
		sort(X2.begin(), X2.end());
		vii X;
		int i = 0, j = 0;
		while(i < X1.size() && j < X2.size()) {
			if(X.size()+1 < X1[i].first) X.push_back(X2[j++]);
			else {
				X.emplace_back(-X1[i].first, X1[i].second);
				++ i;
			}
		}
		for(; i < X1.size(); ++i) X.emplace_back(-X1[i].first, X1[i].second);
		for(; j < X2.size(); ++j) X.push_back(X2[j]);

		vii E;
		vi res(D), ts(C+1, -1);
		ts[1] = 0;
		for(int i = 0; i < D; ++i) {
			cin >> u >> v;
			E.emplace_back(u, v);
		}

		int c = 1, t = 0;
		for(const auto &p : X) {
			x = p.first;
			int i = p.second;
			if(x < 0) {
				if(c == -x) {
					t += 1;
					for(const pii e : E) {
						if(e.first == i && ts[e.second] >= 0) t = max(t, ts[e.second]+1);
						else if(e.second == i && ts[e.first] >= 0) t = max(t, ts[e.first]+1);
					}
				}
			} else t = x;
			ts[i] = t;
			++ c;
			for(int d = 0; d < D; ++d) {
				if(E[d].first == i && ts[E[d].second] >= 0) res[d] = max(1, t-ts[E[d].second]);
				else if(E[d].second == i && ts[E[d].first] >= 0) res[d] = max(1, t-ts[E[d].first]);
			}
		}

		cout << "Case #" << tt << ":";
		for(int d = 0; d < D; ++d) cout << " " << res[d];
		cout << "\n";
	}

	return 0;
}