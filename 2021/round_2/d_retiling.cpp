#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
const int MAX_N = 105;

int R, C, F, S, N;
int match[MAX_N], vis[MAX_N];
vi G[MAX_N];

bool augment(int i, int v) {
	if(vis[i] == v) return false;
	vis[i] = v;
	for(int j : G[i]) {
		if(match[j] == -1 || augment(match[j], v)) {
			match[i] = j;
			match[j] = i;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> R >> C >> F >> S;
		vector<string> tiles[2];
		for(int i = 0; i < 2; ++i) {
			tiles[i].resize(R);
			for(int j = 0; j < R; ++j)
				cin >> tiles[i][j];
		}
		N = R*C;	
		int ans = 0;

		for(int i = 0; i < R; ++i) {
			for(int j = 0; j < C; ++j) {
				int u = i*C+j;
				G[u].clear();
				if(tiles[0][i][j] == tiles[1][i][j]) continue;
				++ ans;
				vi neighb;
				if(i > 0) neighb.push_back(u-C);
				if(j > 0) neighb.push_back(u-1);
				for(int v : neighb) {
					int i2 = v/C, j2 = v%C;
					if(tiles[0][i2][j2] == tiles[1][i2][j2]) continue;
					if(tiles[0][i][j] == tiles[0][i2][j2]) continue;
					G[u].push_back(v);
					G[v].push_back(u);
				}
			}
		}

		for(int i = 0; i < N; ++i) {
			match[i] = -1;
			vis[i] = -1;
		}
		for(int i = 0; i < N; ++i)
			if(match[i] == -1 && augment(i, i))
				-- ans;
		
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}