import sys

T, B = map(int, input().split())

for _ in range(T):
	a = [None]*B
	same, diff = -1, -1
	comp, rev = False, False
	i, j = 0, 0
	while True:
		if j >= B//2 or i >= 150: break
		if i % 10 == 0:
			if same >= 0:
				print(same+1, flush=True)
				ans = int(input())
				comp = (ans != a[same])
				i += 1
			else: comp = False
			if diff >= 0:
				print(diff+1, flush=True)
				ans = int(input())
				if comp: ans = 1-ans
				rev = (ans != a[diff])
				i += 1
			else: rev = False
		if i % 10 < 9:
			# First
			print(j+1, flush=True)
			ans = int(input())
			if comp: ans = 1-ans
			if rev: a[B-1-j] = ans
			else: a[j] = ans
			# Second
			print(B-j, flush=True)
			ans = int(input())
			if comp: ans = 1-ans
			if rev: a[j] = ans
			else: a[B-1-j] = ans
			# Find same or diff
			if a[j] == a[B-1-j]:
				if same < 0: same = j
			else:
				if diff < 0: diff = j
			j += 1
			i += 2
		else:
			print(1, flush=True)
			input()
			i += 1
	if comp: a = [1-v for v in a]
	if rev: a = list(reversed(a))
	res = ""
	for v in a:
		res += str(v)
	print(res, flush=True)
	ans = input()
	print(ans, i, file=sys.stderr)
	if ans == 'N':
		exit(0)