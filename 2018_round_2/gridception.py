T = int(input())

for t in range(1, T+1):
	R, C = map(int, input().split())
	m = []
	for i in range(R):
		m.append(input())
	res = 0
	for pi in range(16):
		p = [['B' if pi&1 else 'W', 'B' if pi&2 else 'W'],
			['B' if pi&4 else 'W', 'B' if pi&8 else 'W']]
		for i in range(R+1):
			for j in range(C+1):
				seen = [[False]*C for _ in range(R)]
				for x0 in range(R):
					for y0 in range(C):
						if seen[x0][y0]: continue
						seen[x0][y0] = True
						a = 0 if x0 < i else 1
						b = 0 if y0 < j else 1
						if m[x0][y0] != p[a][b]: continue
						r = 0
						stack = [(x0, y0)]
						while len(stack) > 0:
							r += 1
							x, y = stack.pop()
							for x2, y2 in [(x-1, y), (x+1, y), (x, y-1), (x, y+1)]:
								if x2 >= 0 and x2 < R and y2 >= 0 and y2 < C:
									if seen[x2][y2]: continue
									seen[x2][y2] = True
									a = 0 if x2 < i else 1
									b = 0 if y2 < j else 1
									if m[x2][y2] == p[a][b]: stack.append((x2, y2))
						res = max(res, r)
	print("Case #{}: {}".format(t, res))