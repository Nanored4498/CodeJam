T = int(input())
for t in range(T):
	N = int(input())
	W = []
	for _ in range(N):
		W.append(input())
	L = []
	res = 0
	for ai in range(N):
		a = W[ai]
		for bi in range(ai+1, N):
			if ai == bi:
				continue
			b = W[bi]
			i = 0
			while i < len(a) and i < len(b):
				if a[-i-1] == b[-i-1]:
					i += 1
				else:
					break
			if i > 0:
				L.append((-i, ai, bi))
	L.sort()
	suff = dict()
	added = [False] * N
	res = 0
	for i, a, b in L:
		if res+2 > N:
			break
		if not(added[a]) and not(added[b]):
			i2 = i
			while i2 < 0 and W[a][i2:] in suff:
				i2 = suff[W[a][i2:]] + 1
			if i2 < 0:
				suff[W[a][i2:]] = i2
				suff[W[a][i:]] = i2
				added[a] = added[b] = True
				res += 2
	print("Case #{}: {}".format(t+1, res))