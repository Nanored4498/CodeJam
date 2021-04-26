#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {

	int T, N, B;
	ll P;
	cin >> T >> N >> B >> P;
	const int nSteps = N*B;
	const ll mP = 9e17;
	const int top0 = P < mP ? 8 : 9;
	const int sec0 = P < mP ? 8 : 9;

	while(T--) {
		vi h(N, 0);
		int r = N;
		int top = top0;
		int sec = sec0;
		for(int s = 0; s < nSteps; ++s) {
			int D, ans = -1;
			cin >> D;
			if(D == -1) return 0;
			if(D >= top) {
				for(int i = 0; i < N; ++i) if(h[i] == B-1) {
					ans = i;
					break;
				}
			}
			if(ans == -1 && D >= sec) {
				for(int i = 0; i < N; ++i) if(h[i] == B-2) {
					ans = i;
					break;
				}
			}
			if(ans == -1) {
				for(int i = 0; i < N; ++i) if(h[i] < B-2) {
					ans = i;
					break;
				}
			}
			if(ans == -1) {
				for(int i = 0; i < N; ++i) if(h[i] < B-1) {
					ans = i;
					break;
				}
			}
			if(ans == -1) {
				for(int i = 0; i < N; ++i) if(h[i] < B) {
					ans = i;
					break;
				}
			}
			cout << ans+1 << endl;
			++ h[ans];
			if(h[ans] == B-2) {
				--r;
				if(r == 16 || r == 12 || r == 8 || r == 4) -- sec;
			}
		}
	}

	int good;
	cin >> good;

	return 0;
}