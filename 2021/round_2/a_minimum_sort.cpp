#include <iostream>

using namespace std;

int main() {

	int T, N, j;
	cin >> T >> N;
	for(int t = 1; t <= T; ++t) {
		for(int i = 1; i < N; ++i) {
			cout << "M " << i << " " << N << endl;
			cin >> j;
			if(j == -1) return 0;
			if(j > i) {
				cout << "S " << i << ' ' << j << endl;
				cin >> j;
				if(j == -1) return 0;
			}
		}
		cout << 'D' << endl;
		cin >> j;
		if(j == -1) return 0;
	}

	return 0;
}