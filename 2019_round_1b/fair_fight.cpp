#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
        int N, K;
        cin >> N >> K;
        vector<int> C, D;
        int skill;
        for(int i = 0; i < N; i++) {
            cin >> skill;
            C.push_back(skill); 
        }
        for(int i = 0; i < N; i++) {
            cin >> skill;
            D.push_back(skill); 
        }
        long long res = 0;
        for(int i = 0; i < N; i++) {
            int maxc = 0, maxd = 0;
            for(int j = i; j < N; j++) {
                maxc = max(maxc, C[j]);
                maxd = max(maxd, D[j]);
                if(abs(maxc - maxd) <= K) res ++;
            }
        }
        cout << "Case #" << t << ": " << res << "\n";
    }

    return 0;
}