T = int(input())
for t in range(1, T+1):
	N = int(input())
	P = []
	for _ in range(N):
		P.append(input())
	start = ""
	end = ""
	mid = ""
	bad = False
	for p in P:
		l = len(p)
		i = 0
		while p[i] != '*':
			if i >= len(start):
				start += p[i]
			elif p[i] != start[i]:
				bad = True
				break
			i+=1
		if bad: break
		j = 0
		while p[l-1-j] != '*':
			if j >= len(end):
				end = p[l-1-j] + end
			elif p[l-1-j] != end[-1-j]:
				bad = True
				break
			j+=1
		for k in range(i+1, l-1-j):
			if p[k] != '*':
				mid += p[k]
	if bad:
		res = "*"
	else:
		res = start+mid+end
	print("Case #{}: {}".format(t, res))