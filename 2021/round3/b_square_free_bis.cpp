#include <iostream>
#include <algorithm>

using namespace std;
const int MRC = 21;

int R, C;
int S[MRC], D[MRC];
char ans[MRC][MRC];
int order[MRC];

void solve() {
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			ans[i][j] = '\\';
	for(int j = 0; j < C; ++j) order[j] = j;

	for(int i = 0; i < R; ++i) {
		sort(order, order+C, [&](int j, int j2) { return D[j] > D[j2]; });
		for(int s = 0; s < S[i]; ++s) {
			-- D[order[s]];
			ans[i][order[s]] = '/';
		}
	}
	for(int j = 0; j < C; ++j) if(D[j] != 0) {
		cout << "IMPOSSIBLE\n";
		return;
	}

	bool modif = true;
	while(modif) {
		modif = false;
		for(int j = 1; j < C; ++j) {
			int a = 0;
			while(a < R && !(ans[a][j-1] == '/' && ans[a][j] == '\\')) ++ a;
			if(a == R) continue;
			int b = R-1;
			while(b > a && !(ans[b][j-1] == '\\' && ans[b][j] == '/')) -- b;
			if(b == a) continue;
			modif = true;
			swap(ans[a][j-1], ans[b][j-1]);
			swap(ans[a][j], ans[b][j]);
		}
	}

	cout << "POSSIBLE\n";
	for(int i = 0; i < R; ++i) {
		for(int j = 0; j < C; ++j) cout << ans[i][j];
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		cin >> R >> C;
		for(int i = 0; i < R; ++i) cin >> S[i];
		for(int j = 0; j < C; ++j) cin >> D[j];
		solve();
	}

	return 0;
}