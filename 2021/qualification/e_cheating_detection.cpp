#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

const int Q = 10000;
const int R = 100;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s[R];
	int T, P;
	cin >> T >> P;
	for(int t = 1; t <= T; ++t) {
		vi c(Q, 0);
		for(int i = 0; i < R; ++i) {
			cin >> s[i];
			for(int j = 0; j < Q; ++j) if(s[i][j] == '1') ++ c[j];
		}
		double ms = 0.;
		int ans = 1;
		for(int i = 0; i < R; ++i) {
			double score = 0., good = 0.;
			for(int j = 0; j < Q; ++j) if(s[i][j] == '1') {
				if(c[j] < 20) score += 20 - c[j];
				++ good;
			}
			score /= good;
			if(score > ms) {
				ms = score;
				ans = i+1;
			}
		}
		cout << "Case #" << t << ": " << ans << "\n";
	}
}