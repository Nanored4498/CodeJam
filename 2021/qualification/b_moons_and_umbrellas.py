T = int(input())
inf = 10**8
for t in range(1, T+1):
	X, Y, S = input().split()
	X, Y = int(X), int(Y)
	dp = [inf if S[0] == 'J' else 0, inf if S[0] == 'C' else 0]
	for s in S[1:]:
		dp = [inf if s == 'J' else min(dp[0], dp[1]+Y), inf if s == 'C' else min(dp[0]+X, dp[1])]
	print("Case #{}: {}".format(t, min(dp)))