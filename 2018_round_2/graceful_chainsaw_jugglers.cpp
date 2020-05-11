#include <iostream>

using namespace std;

int m[502][501][501];
int f(int i, int r, int b) {
	int& res = m[i][r][b];
	if(res != -1) return res;
	res = 0;
	if(i == 501) return 0;
	int j = 0;
	while(r >= 0 && b >= 0) {
		res = max(res, f(i+1, r, b) + j);
		r -= i;
		b -= j;
		++ j;
	}
	return res;
}

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	for(int i = 0; i <= 501; i++)
		for(int j = 0; j <= 500; j++)
			for(int k = 0; k <= 500; k++)
				m[i][j][k] = -1;

	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int R, B;
		cin >> R >> B;
		cout << "Case #" << t << ": " << f(0, R, B)-1 << "\n";
	}

	return 0;
}