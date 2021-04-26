T = int(input())
M = 2501
for t in range(1, T+1):
	N = int(input())
	c = [0]*M
	for _ in range(2*N-1):
		for h in map(int, input().split()):
			c[h] += 1
	ans = []
	for i in range(M):
		if c[i]&1:
			ans.append(str(i))
	print("Case #{}: {}".format(t, ' '.join(ans)))