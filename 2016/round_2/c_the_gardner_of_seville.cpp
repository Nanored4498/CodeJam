#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int R, C;

struct Start {
	int x, y, dir;
};

Start getStart(int i) {
	-- i;
	if(i < C) return { -1, i, 0 };
	i -= C;
	if(i < R) return { i, C, 1 };
	i -= R;
	if(i < C) return { R, C-1-i, 2 };
	i -= C;
	return { R-1-i, -1, 3 };
}

void move(int &r, int &c, int d) {
	if(d == 0) r += 1;
	else if(d == 1) c -= 1;
	else if(d == 2) r -= 1;
	else c += 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> R >> C;
		int N = R+C;
		vii G(N);
		for(int i = 0; i < R+C; ++i)
			cin >> G[i].first >> G[i].second;
		const auto dist = [&](int i, int j)->int {
			return min(abs(j-i), 2*N-abs(j-i));
		};
		sort(G.begin(), G.end(), [&](const pii &a, const pii &b) {
			return dist(a.first, a.second) < dist(b.first, b.second);
		});
		bool bad = false;
		vector<string> ans(R, string(C, ' '));
		for(pii &p : G) {
			if((p.second - p.first + 2*N) % (2*N) > N)
				swap(p.first, p.second);
			auto [r, c, d] = getStart(p.first);
			move(r, c, d);
			while(r >= 0 && r < R && c >= 0 && c < C) {
				if(ans[r][c] == ' ') ans[r][c] = "\\/\\/"[d];
				if(ans[r][c] == '\\') d = 3-d;
				else d ^= 1;
				move(r, c, d);
			}
			auto [r2, c2, _] = getStart(p.second);
			if(r != r2 || c != c2) {
				bad = true;
				break;
			}
		}
		cout << "Case #" << t << ":\n";
		if(bad) cout << "IMPOSSIBLE\n";
		else {
			for(string &s : ans) {
				for(char &c : s) if(c == ' ') c = '/';
				cout << s << '\n';
			}
		}
	}

	return 0;
}