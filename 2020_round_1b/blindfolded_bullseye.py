import sys
T, A, B = map(int, input().split())
MAX = int(1e9)

def send(t, i, j):
	print(i, j, flush=True)
	ans = input()
	# print(t, i, j, ans, file=sys.stderr)
	return ans

for t in range(T):
	found = False
	q = MAX//2
	tests = [(-q, -q), (-q, q), (q, -q), (q, q), (0, 0)]
	s = None
	for i, j in tests:
		ans = send(t, i, j)
		if ans == "HIT":
			s = (i, j)
			break
	if s == None: exit(0)
	i, j = s
	found = False
	# LEFT
	a, b = max(-MAX, i-2*B), i
	while a < b:
		m = (a+b) // 2
		ans = send(t, m, j)
		if ans == "CENTER":
			found = True
			break
		elif ans == "HIT": b = m
		else: a = m+1
	if found: continue
	# RIGHT
	a, b, i = i, min(MAX, i+2*B), a
	while a < b:
		m = (a+b+1) // 2
		ans = send(t, m, j)
		if ans == "CENTER":
			found = True
			break
		elif ans == "HIT": a = m
		else: b = m-1
	if found: continue
	i = (i+a)//2
	# TOP
	a, b = max(-MAX, j-2*B), j
	while a < b:
		m = (a+b) // 2
		ans = send(t, i, m)
		if ans == "CENTER":
			found = True
			break
		elif ans == "HIT": b = m
		else: a = m+1
	if found: continue
	# BOT
	a, b, j = j, min(MAX, j+2*B), a
	while a < b:
		m = (a+b+1) // 2
		ans = send(t, i, m)
		if ans == "CENTER":
			found = True
			break
		elif ans == "HIT": a = m
		else: b = m-1
	if found: continue
	j = (j+a)//2
	tests = [(i, j), (i+1, j), (i, j+1), (i+1, j+1), (i-1, j), (i, j-1), (i-1, j-1)]
	for i, j in tests:
		ans = send(t, i, j)
		if ans == "CENTER": break
		elif ans == "WRONG": exit(0)