#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int K, N;
		cin >> K >> N;
		vi X(N), T(N);
		for(int i = 0; i < N; ++i) cin >> X[i];
		for(int i = 0; i < N; ++i) cin >> T[i];
		cout << "Case #" << t << ": ";
	}

	return 0;
}