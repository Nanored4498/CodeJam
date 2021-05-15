T = int(input())
for t in range(1, T+1):
	N, C, M = map(int, input().split())
	cp, cb = [0]*N, [0]*C
	for _ in range(M):
		P, B = map(int, input().split())
		cp[P-1] += 1
		cb[B-1] += 1
	cp0 = cp.copy()
	y0 = max(cb)
	y = max(y0, max(cp))
	while y > y0:
		available = []
		imp = False
		for i in range(N):
			if cp[i]+1 < y: available.append(i)
			elif cp[i] == y:
				if len(available) == 0:
					imp = True
					break
				cp[i] -= 1
				cp[available[-1]] += 1
				if cp[available[-1]]+1 >= y: available.pop()
		if imp: break
		else: y -= 1
	z = 0
	for i in range(N):
		z += max(0, cp0[i] - y)
	print("Case #{}: {} {}".format(t, y, z)) 