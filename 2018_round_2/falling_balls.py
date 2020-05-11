T = int(input())
for t in range(1, T+1):
	C = int(input())
	B = list(map(int, input().split()))
	if B[0] == 0 or B[-1] == 0:
		print("Case #{}: IMPOSSIBLE".format(t))
	else:
		res = [['.']*C]
		to = 0
		for i in range(C):
			while B[to] == 0:
				to += 1
			B[to] -= 1
			r = 0
			while i > to:
				if r+1 >= len(res): res.append(['.']*C)
				res[r][i] = '/'
				r += 1
				i -= 1
			while i < to:
				if r+1 >= len(res): res.append(['.']*C)
				res[r][i] = '\\'
				r += 1
				i += 1
		print("Case #{}: {}".format(t, len(res)))
		for r in res:
			print(''.join(r))