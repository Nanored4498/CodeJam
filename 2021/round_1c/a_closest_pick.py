T = int(input())
for t in range(1, T+1):
	N, K = map(int, input().split())
	P = list(map(int, input().split()))
	P.sort()
	ans = 0
	r = [P[0]-1, K-P[-1]]
	for i in range(1, N):
		x = P[i] - P[i-1]
		ans = max(ans, x-1)
		r.append(x//2)
	r.sort()
	ans = max(ans, r[-1]+r[-2])
	print("Case #{}: {}".format(t, ans/K))