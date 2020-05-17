T = int(input())
for t in range(1, T+1):
	N = int(input())
	res = [None]*N
	activities = []
	for i in range(N):
		S, E = map(int, input().split())
		activities.append((S, E, i))
	ce, je = 0, 0
	activities.sort()
	for s, e, i in activities:
		if ce <= s:
			res[i] = 'C'
			ce = e
		elif je <= s:
			res[i] = 'J'
			je = e
		else:
			res = "IMPOSSIBLE"
			break
	print("Case #{}: {}".format(t, ''.join(res)))