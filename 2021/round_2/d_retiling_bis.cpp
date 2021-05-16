#include <iostream>
#include <vector>
#include <limits>

using namespace std;

template<typename INT>
struct Hungarian {
	int N, M;
	vector<int> xy, yx, slackx;
	vector<INT> lx, ly, slack;
	vector<bool> S, T;
	vector<vector<INT>> w;

	Hungarian(int N, int M):
		N(N), M(M),
		xy(N, -1), lx(N, numeric_limits<INT>::max()),
		yx(M, -1), ly(M, 0),
		slack(M), slackx(M),
		w(N, vector<int>(M)) { }
	
	bool add(int j) {
		T[j] = true;
		int i = yx[j];
		if(i == -1) {
			while(j >= 0) swap(j, xy[yx[j] = slackx[j]]);
			return true;
		}
		if(S[i]) return false;
		S[i] = true;
		for(int j2 = 0; j2 < M; ++j2) if(!T[j2]) {
			INT new_slack = w[i][j2] - lx[i] - ly[j2];
			if(new_slack < slack[j2]) {
				slack[j2] = new_slack;
				slackx[j2] = i;
				if(new_slack == 0 && add(j2)) return true;
			}
		}
		return false;
	}

	void augment() {
		S.assign(N, false);
		T.assign(M, false);
		int i = 0;
		while(xy[i] != -1) ++i;
		S[i] = true;
		for(int j = 0; j < M; ++j) {
			slackx[j] = i;
			slack[j] = w[i][j] - lx[i] - ly[j];
		}
		while(true) {
			for(int j = 0; j < M; ++j)
				if(!T[j] && slack[j] == 0 && add(j))
					return;
			INT delta = numeric_limits<INT>::max();
			for(int j = 0; j < M; ++j) if(!T[j]) delta = min(delta, slack[j]);
			for(int i = 0; i < N; ++i) if(S[i]) lx[i] += delta;
			for(int j = 0; j < M; ++j)
				if(T[j]) ly[j] -= delta;
				else slack[j] -= delta;
		}
	}

	void solve() {
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				lx[i] = min(lx[i], w[i][j]);
		for(int i = 0; i < N; ++i) augment();
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int R, C, F, S;
		cin >> R >> C >> F >> S;
		vector<string> tiles[2];
		for(int i = 0; i < 2; ++i) {
			tiles[i].resize(R);
			for(int j = 0; j < R; ++j)
				cin >> tiles[i][j];
		}	

		vector<pair<int, int>> A, B;
		for(int i = 0; i < R; ++i) {
			for(int j = 0; j < C; ++j) {
				if(tiles[0][i][j] == tiles[1][i][j]) continue;
				if(tiles[0][i][j] == 'M') A.emplace_back(i, j);
				else B.emplace_back(i, j);
			}
		}
		if(A.size() > B.size()) swap(A, B);

		Hungarian<int> H(A.size(), B.size());
		for(int i = 0; i < H.N; ++i)
			for(int j = 0; j < H.M; ++j)
				H.w[i][j] = min(
					S * (abs(A[i].first - B[j].first) + abs(A[i].second - B[j].second)),
					F * 2
				);
		H.solve();

		int ans = F * (H.M - H.N);
		for(int i = 0; i < H.N; ++i) ans += H.w[i][H.xy[i]];
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}