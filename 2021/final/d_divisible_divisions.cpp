#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const ll MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        string s;
        ll D;
        cin >> s >> D;
        int n = s.size();
        vi DP(n+1, 0), DP2(n+1, 0);
        DP[0]=1;
        for(int i = 1; i <= n; ++i) {
            ll x = 0, m = 1;
            for(int j = i-1; j >= 0; --j) {
                x = (x+m*(s[j]-'0'))%D;
                m = (m*10)%D;
                if(x == 0) DP[i] = (DP[i]+DP[j]+DP2[j])%MOD;
                else DP2[i] = (DP2[i]+DP[j])%MOD;
            }
        }
        cout << "Case #" << t << ": " << (DP[n]+DP2[n])%MOD << '\n';
    }
    
    return 0;
}