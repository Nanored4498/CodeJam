#include <iostream>
#include <vector>

using namespace std;
const int MAX_N = 1e6+5;

vector<int> ps[MAX_N];
int ans[MAX_N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(int i = 2; i < MAX_N; ++i) if(ps[i].empty())
		for(int j = i; j < MAX_N; j += i)
			ps[j].push_back(i);
	
	ans[1] = ans[2] = 1;
	for(int i = 3; i < MAX_N; ++i) {
		ans[i] = 1;
		for(int p : ps[i-1])
			ans[i] = max(ans[i], 1 + ans[(i-1)/p]);
		for(int p : ps[i])
			ans[i] = max(ans[i], ans[i/p]);
	}

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N, y = 1;
		cin >> N;
		for(int p : ps[N])
			if(p >= 3) y = max(y, ans[N/p]);
			else if((N&3) == 0) y = max(y, ans[N/4]);
		cout << "Case #" << t << ": " << y << '\n';
	}

	return 0;
}