T = int(input())
for t in range(1, T+1):
	N = int(input())
	L = list(map(int, input().split()))
	c = 0
	for i in range(N-1):
		j = i
		for k in range(i+1, N):
			if L[k] < L[j]: j = k
		c += j - i + 1
		for k in range((j-i+1)//2):
			L[i+k], L[j-k] = L[j-k], L[i+k]
	print("Case #{}: {}".format(t, c))