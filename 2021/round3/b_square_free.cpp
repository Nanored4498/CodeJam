#include <iostream>

using namespace std;
const int MRC = 21;

int R, C;
int S[MRC], D[MRC], d[MRC], s[MRC]; // '/'
char ans[MRC][MRC];

bool solve(int i, int j) {
	if(j == C) {
		++ i;
		j = 0;
	}
	if(i == R) {
		for(int size = 1; 2*size <= min(R, C); ++ size) {
			for(int x = 0; x+2*size <= R; ++x) {
				for(int y = 0; y+2*size <= C; ++y) {
					bool square = true;
					for(int s = 0; s < size; ++s) {
						if(ans[x+size-1-s][y+s] == '\\') { square = false; break; }
						if(ans[x+2*size-1-s][y+size+s] == '\\') { square = false; break; }
						if(ans[x+s][y+size+s] == '/') { square = false; break; }
						if(ans[x+size+s][y+s] == '/') { square = false; break; }
					}
					if(square) return false;
				}
			}
		}
		return true;
	}
	if(s[i] + C-j-1 >= S[i] && d[j] + R-i-1 >= D[j]) {
		ans[i][j] = '\\';
		if(solve(i, j+1)) return true;
	}
	if(s[i]+1 <= S[i] && d[j]+1 <= D[j]) {
		ans[i][j] = '/';
		++ s[i];
		++ d[j];
		if(solve(i, j+1)) return true;
		-- s[i];
		-- d[j];
	}
	return false;
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
		for(int i = 0; i < C; ++i) cin >> D[i];
		for(int i = 0; i < R; ++i) s[i] = 0;
		for(int i = 0; i < C; ++i) d[i] = 0;
		if(solve(0, 0)) {
			cout << "POSSIBLE\n";
			for(int i = 0; i < R; ++i) {
				for(int j = 0; j < C; ++j)
					cout << ans[i][j];
				cout << '\n';
			}
		} else cout << "IMPOSSIBLE\n";
	}

	return 0;
}