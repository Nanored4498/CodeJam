#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
typedef vector<int> vi;
typedef tuple<int, int, int> t3i;

bool f(int i, vi &vals, vector<vi> &G) {
	int b = i >> 1, d = i&1;
	if(vals[b] != -1) return vals[b] == d;
	vals[b] = d;
	for(int j : G[i]) if(!f(i, vals, G)) {
		vals[b] = -1;
		return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int R, C;
		cin >> R >> C;
		vector<string> m(R);
		for(int i = 0; i < R; ++i) {
			cin >> m[i];
			for(char &c : m[i]) if(c == '|') c = '-';
		}
		cout << "Case #" << t << ": ";
		
		vi vals;
		vector<vi> cs[2] { { R, vi(C, -1) }, { R, vi(C, -1) } };
		vi dx {1, 0, -1, 0};
		vi dy {0, 1, 0, -1};
		bool bad = false;
		for(int i = 0; i < R; ++i) {
			for(int j = 0; j < C; ++j) {
				if(m[i][j] != '-') continue;
				int b = 2 * vals.size();
				vals.push_back(-1);
				vector<t3i> seen[2];
				for(int d0 = 0; d0 < 4; ++d0) {
					int d = d0;
					int x = i + dx[d];
					int y = j + dy[d];
					while(x >= 0 && y >= 0 && x < R && y < C && m[x][y] != '#') {
						if(m[x][y] == '-') {
							if(vals.back() == (d0&1)) bad = true;
							vals.back() = (d0&1) ^ 1;
							break;
						} else if(m[x][y] == '.') seen[d0&1].emplace_back(d&1, x, y);
						else if(m[x][y] == '/') d ^= 3;
						else d ^= 1;
						x += dx[d];
						y += dy[d];
					}
				}
				for(int d0 : {0, 1}) if(vals.back() != (d0^1)) {
					for(const auto &[d, x, y] : seen[d0])
						cs[d][x][y] = b + d0;
				}
			}
		}

		vector<vi> G(2*vals.size());
		for(int i = 0; i < R; ++i) {
			for(int j = 0; j < C; ++j) {
				if(m[i][j] != '.') continue;
				int a = cs[0][i][j], b = cs[1][i][j];
				if(vals[a>>1] == ((a&1)^1)) a = -1;
				if(vals[b>>1] == ((b&1)^1)) b = -1;
				if(a == -1) {
					if(b == -1) bad = true;
					else vals[b>>1] = b&1;
				} else {
					if(b == -1) vals[a>>1] = a&1;
					else {
						G[a^1].push_back(b);
						G[b^1].push_back(a);
					}
				}
			}
		}

		for(int i = 0; i < vals.size(); ++i) if(vals[i] == -1) {
			if(!f(2*i, vals, G) && !f(2*i+1, vals, G)) {
				bad = true;
				break;
			}
		}
		if(!bad) for(int i = 0; i < vals.size(); ++i) {
			int d = vals[i];
			vals[i] = -1;
			if(!f(2*i+d, vals, G)) {
				bad = true;
				break;
			}
		}

		if(bad) cout << "IMPOSSIBLE\n";
		else {
			cout << "POSSIBLE\n";
			int b = 0;
			for(int i = 0; i < R; ++i) {
				for(int j = 0; j < C; ++j) {
					if(m[i][j] != '-') continue;
					if(vals[b++] == 0) m[i][j] = '|';
				}
				cout << m[i] << '\n';
			}
		}

	}

	return 0;
}