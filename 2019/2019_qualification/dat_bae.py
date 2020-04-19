import sys

T = int(input())

for x in range(T):
	N, B, F = map(int, input().split())
	# First pass
	req = ""
	b = '0'
	nbs = []
	while len(req) < N:
		l = min(16, N-len(req))
		req += b * l
		nbs.append(0)
		b = '0' if b == '1' else '1'
	print(req)
	sys.stdout.flush()
	ans = input()
	b = '0'
	i, j = 0, 0
	while i < len(ans):
		if ans[i] == b:
			i += 1
			nbs[j] += 1
		else:
			j += 1
			b = '0' if b == '1' else '1'
	#print(req, "-->", ans, "-->", nbs, file=sys.stderr)

	# Divide and conquer
	s = 16
	while s >= 2:
		req = ""
		nbs2 = []
		while len(req) < N:
			l = min(s, N-len(req))
			l0 = min(s//2, l)
			l1 = l-l0
			req += '0' * l0 + '1' * l1
			nbs2.append(0)
			if l1 > 0:
				nbs2.append(0)
		print(req)
		sys.stdout.flush()
		ans = input()
		j = 0
		for i in range(len(nbs)):
			for _ in range(nbs[i]):
				nbs2[2*i + ord(ans[j]) - ord('0')] += 1
				j += 1
		nbs = nbs2
		s //= 2
		# print(req, "--->", ans, "--->", nbs, file=sys.stderr)

	res = []
	for i in range(N):
		if nbs[i] == 0:
			res.append(str(i))
	res = " ".join(res)
	# print(nbs, file=sys.stderr)
	#print(res, file=sys.stderr)
	print(res)
	sys.stdout.flush()
	ans = input()
	if ans == "-1":
		break
