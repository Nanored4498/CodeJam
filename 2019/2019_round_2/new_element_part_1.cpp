#include <iostream>
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b) { 
   if (b == 0) return a; 
   return gcd(b, a % b);  
} 

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for(int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		vector<int> C, J;
		set<pair<int, int>> frac;
		int a, b;
		for(int i = 0; i < N; i++) {
			cin >> a >> b;
			C.push_back(a);
			J.push_back(b);
			for(int j = 0; j < i; j++) {
				if((C[j] < a && J[j] > b) || (C[j] > a && J[j] < b)) {
					int num = abs(C[j] - a);
					int den = abs(J[j] - b);
					int g = gcd(num, den);
					frac.insert({num/g, den/g});
				}
			}
		}
		int res = frac.size() + 1;
		cout << "Case #" << t << ": " << res << "\n";
	}

	return 0;
}