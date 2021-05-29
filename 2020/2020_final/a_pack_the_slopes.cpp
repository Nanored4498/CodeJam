#include <iostream>
#include <vector>
#include <algorithm>

#include "../CPHeaders/lazy_segment_tree.h"

using namespace std;
typedef long long ll;
const int MAX_N = 1e5+5;

struct Edge {
	int v;
	ll s, c;
	Edge(int v, ll s, ll c): v(v), s(s), c(c) {}
};
vector<Edge> G[MAX_N];

int ss[MAX_N];
int P = 1;
pair<int, int> pp[MAX_N];
pair<int, int> pred[MAX_N];
ll C[MAX_N];
vector<ll> S[MAX_N];
vector<LazySegmentTree<ll>> seg;

int subtreeSize(int i) {
	ss[i] = 1;
	for(const Edge &e : G[i])
		ss[i] += subtreeSize(e.v);
	return ss[i];
}

void heavyLight(int i, int p, int j) {
	pp[i].first = p;
	pp[i].second = j;
	int next = -1;
	for(const Edge &e : G[i])
		if(next == -1 || ss[next] < ss[e.v])
			next = e.v;
	for(const Edge &e : G[i]) {
		C[e.v] = C[i] + e.c;
		if(e.v == next) {
			S[p].push_back(e.s);
			heavyLight(e.v, p, j+1);
		} else {
			pred[P] = pp[i];
			S[P].clear();
			S[P].push_back(e.s);
			heavyLight(e.v, P++, 0);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const function<ll(ll, ll)> op = [](ll i, ll j) { return min(i, j); };
	const function<ll(ll, int)> pow_op = [](ll i, int p) { return i; };

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		for(int i = 1; i <= N; ++i) G[i].clear();
		for(int i = 1; i < N; ++i) {
			int u, v;
			ll s, c;
			cin >> u >> v >> s >> c;
			G[u].emplace_back(v, s, c);
		}

		subtreeSize(1);
		P = 1;
		C[1] = 0;
		S[0].clear();
		S[0].push_back(1e11);
		heavyLight(1, 0, 0);

		seg.clear();
		for(int p = 0; p < P; ++p) {
			int n = S[p].size();
			seg.emplace_back(n, op, pow_op, 1e11);
			for(int i = 0; i < n; ++i) seg[p].setInit(i, S[p][i]);
			seg[p].init();
		}
		
		vector<int> order(N-1);
		for(int i = 0; i < N-1; ++i) order[i] = i+2;
		sort(order.begin(), order.end(), [&](int i, int j) {
			return C[i] < C[j];
		});

		ll count = 0, expense = 0;
		for(int i : order) {
			pair<int, int> pj = pp[i];
			ll ms = 1e11;
			while(true) {
				ms = min(ms, seg[pj.first].querry(0, pj.second));
				if(pj.first == 0) break;
				pj = pred[pj.first];
			}
			count += ms;
			expense += ms * C[i];
			pj = pp[i];
			while(true) {
				seg[pj.first].add(0, pj.second, -ms);
				if(pj.first == 0) break;
				pj = pred[pj.first];
			}
		}

		cout << "Case #" << t << ": " << count << ' ' << expense << '\n';
	}

	return 0;
}