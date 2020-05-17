#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int T, K, Q, LRP;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for(int tt = 1; tt <= T; ++tt) {
		cin >> K >> Q;
		cin >> s;
		for(int i = 0; i < 3*K; ++i) cin >> LRP;
		vi S(Q), E(Q);
		for(int i = 0; i < Q; ++i) cin >> S[i];
		for(int i = 0; i < Q; ++i) cin >> E[i];

		vi st, m(K);
		for(int i = 0; i < K; ++i) {
			if(s[i] == '(') st.push_back(i);
			else {
				int j = st.back(); st.pop_back();
				m[i] = j;
				m[j] = i;
			}
		}

		long long res = 0;
		vi ds(K, -1);
		for(int i = 0; i < Q; ++i) {
			int s = S[i]-1, t = E[i]-1;
			st.clear();
			st.push_back(s);
			ds[s] = 0;
			int a = 0;
			while(true) {
				int sa = st[a];
				if(sa > 0 && ds[sa-1] < 0) { ds[sa-1] = ds[sa]+1; st.push_back(sa-1); if(sa-1 == t) break; } 
				if(sa+1 < K && ds[sa+1] < 0) { ds[sa+1] = ds[sa]+1; st.push_back(sa+1); if(sa+1 == t) break; }
				if(ds[m[sa]] < 0) { ds[m[sa]] = ds[sa]+1; st.push_back(m[sa]); if(m[sa] == t) break; }
				++ a;
			}
			res += ds[t];
			for(int i : st) ds[i] = -1;
		}

		cout << "Case #" << tt << ": " << res << "\n";
	}

	return 0;
}