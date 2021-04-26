#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N, A, B;
		cin >> N >> A >> B;
		vi U(N);
		for(int i = 0; i < N; ++i) cin >> U[i];
		int y = N-1;
		while(true) {
			if(y > 5000) {
				cout << "Case #" << t << ": IMPOSSIBLE\n";
				break;
			}
			vi c(y+1, 0);
			for(int i = 0; i < N; ++i) c[i] = -U[i];
			++ c[y];
			bool bad = false;
			for(int i = y; i >= 0; --i) {
				if(c[i] < 0) {
					bad = true;
					break;
				}
				if(i >= A) {
					c[i-A] += c[i];
					c[i-A] = min(c[i-A], 1000);
					if(i >= B) {
						c[i-B] += c[i];
						c[i-B] = min(c[i-B], 1000);
					}
				}
			}
			++ y;
			if(!bad) {
				cout << "Case #" << t << ": " << y << '\n';
				break;
			}
		}
	}

	return 0;
}