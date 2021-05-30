#include <iostream>
#include <vector>

using namespace std;
const int MAX_RC = 101;

int r[MAX_RC*MAX_RC], s[MAX_RC*MAX_RC];

int find(int i) {
	if(r[i] == i) return i;
	return r[i] = find(r[i]);
}

void merge(int i, int j) {
	i = find(i);
	j = find(j);
	if(i == j) return;
	if(s[i] < s[j]) swap(i, j);
	r[j] = i;
	s[i] += s[j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int R, C;
		cin >> R >> C;
		vector<string> M(R);
		for(string &s : M) cin >> s;

		int N = R*C;
		for(int i = 0; i < N; ++i) {
			r[i] = i;
			s[i] = 1;
		}
		for(int i = 0; i < R; ++i) {
			for(int j = 0; j < C; ++j) {
				if(i > 0 && M[i][j] == M[i-1][j]) merge(i+R*j, i-1+R*j);
				if(j > 0 && M[i][j] == M[i][j-1]) merge(i+R*j, i+R*j-R);
			}
		}

		vector<string> ans(R-1);
		for(int i = 1; i < R; ++i) {
			for(int j = 1; j < C; ++j) {
				if(M[i][j] == M[i-1][j-1] && find(i+R*j) != find(i-1+R*j-R)) {
					merge(i+R*j, i-1+R*j-R);
					ans[i-1].push_back('\\');
				} else if(M[i-1][j] == M[i][j-1] && find(i-1+R*j) != find(i+R*j-R)) {
					merge(i-1+R*j, i+R*j-R);
					ans[i-1].push_back('/');
				} else {
					ans[i-1].push_back('.');
				}
			}
		}

		int cc = 0;
		for(int i = 0; i < N; ++i) if(find(i) == i) ++ cc;
		cout << "Case #" << t << ": ";
		if(cc == 2) {
			cout << "POSSIBLE\n";
			for(const string &s : ans) cout << s << '\n';
		} else cout << "IMPOSSIBLE\n";
	}

	return 0;
}