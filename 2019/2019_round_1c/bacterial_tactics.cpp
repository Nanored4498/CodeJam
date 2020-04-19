#include <iostream>
#include <set>

using namespace std;

#define N 16
int win[N][N][N][N];
int valid_r[N][N], valid_c[N][N];

int f(int i0, int i1, int j0, int j1, bool first=false) {
	if(i0 == i1 || j0 == j1) return 0;
	int& w = win[i0][i1][j0][j1];
	if(w != -1) return w;
	set<int> s;
	int res = 0;
	for(int i = i0; i < i1; i++)
		if(valid_r[i][j1-1] < j0) {
			int a = f(i0, i, j0, j1) ^ f(i+1, i1, j0, j1);
			s.insert(a);
			if(a == 0) res += j1-j0;
		}
	for(int j = j0; j < j1; j++)
		if(valid_c[i1-1][j] < i0) {
			int a = f(i0, i1, j0, j) ^ f(i0, i1, j+1, j1);
			s.insert(a);
			if(a == 0) res += i1-i0;
		}
	w = 0;
	while(s.count(w) > 0) w ++;
	if(first) return res;
	else return w;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int R, C;
		cin >> R >> C;
		char c;
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				cin >> c;
				if(j == 0) valid_r[i][j] = c == '.' ? -1 : 0;
				else valid_r[i][j] = c == '.' ? valid_r[i][j-1] : j;
				if(i == 0) valid_c[i][j] = c == '.' ? -1 : 0;
				else valid_c[i][j] = c == '.' ? valid_c[i-1][j] : i;
			}
		}
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
				for(int k = i+1; k <= R; k++)
					for(int l = j+1; l <= C; l++)
						win[i][k][j][l] = -1;
		cout << "Case #" << t << ": " << (int) f(0, R, 0, C, true) << "\n";
	}

	return 0;
}