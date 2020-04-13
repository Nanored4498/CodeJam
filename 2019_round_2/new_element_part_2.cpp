#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for(int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		long long a, b, c, d;
		cin >> a >> b;
		double mi=0, ma=1e4;
		bool impossible = false;
		for(int i = 1; i < N; i++) {
			cin >> c >> d;
			if(impossible) continue;
			double e = a-c;
			double f = d-b;
			if(e >= 0 && f <= 0) {
				impossible = true;
				continue;
			}
			if(e != 0 && f != 0) {
				if(f >= 0) mi = max(mi, e/f);
				else ma = min(ma, e/f);
			}
			a = c;
			b = d;
		}
		if(impossible || mi >= ma) cout << "Case #" << t << ": IMPOSSIBLE\n";
		else {
			long long C = 0;
			long long J;
			while(true) {
				C ++;
				J = C*mi;
				while(J-1 > C*mi) J--;
				while(J <= C*mi) J ++;
				if(J < C*ma) break;
			}
			cout << "Case #" << t << ": " << C << " " << J << "\n";
		}
	}

	return 0;
}