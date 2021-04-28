#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int vals[13][3][3];
	int w[3][2] = { {0, 1}, {1, 2}, {2, 0} };
	string ans[13][3];
	ans[0][0] = "R";
	ans[0][1] = "P";
	ans[0][2] = "S";
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			vals[0][i][j] = i==j;
	for(int n = 1; n <= 12; ++n) {
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j)
				vals[n][i][j] = vals[n-1][w[i][0]][j]
								+ vals[n-1][w[i][1]][j];
			if(ans[n-1][w[i][0]] < ans[n-1][w[i][1]])
			 	ans[n][i] = ans[n-1][w[i][0]] + ans[n-1][w[i][1]];
			else
				ans[n][i] = ans[n-1][w[i][1]] + ans[n-1][w[i][0]];
		}
	}

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N, R, P, S;
		cin >> N >> R >> P >> S;
		cout << "Case #" << t << ": ";
		bool imp = true;
		for(int i = 0; i < 3; ++i) {
			if(R != vals[N][i][0] || P != vals[N][i][1] || S != vals[N][i][2]) continue;
			cout << ans[N][i] << '\n';
			imp = false;
			break;
		}
		if(imp) cout << "IMPOSSIBLE\n";
	}

	return 0;
}