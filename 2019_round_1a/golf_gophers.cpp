#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b, long long &u, long long &v) {
	long long q = a / b;
	long long r = a % b;
	if (r == 0) {
		u = 0;
		v = 1;
		return b;
	}
	long long s, t;
	long long d = gcd(b, r, s, t);
	u = t;
	v = s - q * t;
	return d;
}

int main() {
	int T, N, M;
	cin >> T >> N >> M;
	vector<int> primes = {3, 4, 5, 7, 11, 13, 17};
	vector<long long> es;
	long long n = 1;
	for(int p : primes) n *= p;
	for(int p : primes) {
		long long u, v;
		long long np = n / p;
		gcd(np, p, u, v); // np*u + p*v = 1
		long long e = np*u % n;
		if(e < 0) e += n;
		es.push_back(e);
	}

	for(int t = 1; t <= T; t++) {
		long long res = 0;
		for(int k = 0; k < 7; k++) {
			int p = primes[k];
			long long  e = es[k];
			for(int i = 0; i < 18; i++)
				cout << p << " ";
			cout << "\n" << flush;
			long long mod = 0, j;
			for(int i = 0; i < 18; i++) {
				cin >> j;
				mod += j;
			}
			mod = mod % p;
			res = (res + mod*e) % n;
		}
		/********* ERROR HERE *********/
		// This works
		cout << res << "\n" << flush;
		// This doesn't work ===> Runtime Error on your servers
		//cout << res % M << "\n" << flush;
		/*****************************/
		int ans;
		cin >> ans;
		if(ans == -1) {
			cerr << "Bad answer !" << endl;
			return 1;
		}
	}

	return 0;
}