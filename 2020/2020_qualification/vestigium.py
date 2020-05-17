T = int(input())
for t in range(1, T+1):
	N = int(input())
	cols = [[False]*N for _ in range(N)]
	cs = [False]*N
	k, r, c = 0, 0, 0
	for i in range(N):
		lines = [False]*N
		l = list(map(int, input().split()))
		k += l[i]
		repeated_r = False
		for j in range(N):
			if not(repeated_r) and lines[l[j]-1]:
				r += 1
				repeated_r = True
			else: lines[l[j]-1] = True
			if not(cs[j]) and cols[j][l[j]-1]:
				c += 1
				cs[j] = True
			else: cols[j][l[j]-1] = True
	print("Case #{}: {} {} {}".format(t, k, r, c))