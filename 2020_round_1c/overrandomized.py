T = int(input())
for t in range(1, T+1):
	U = int(input())
	letters = {}
	for i in range(10000):
		Q, R = input().split()
		for r in R:
			if r not in letters: letters[r] = 0
		letters[R[0]] += 1
	L = sorted(list(letters), key=lambda c: letters[c])
	res = L[0] + "".join(list(reversed(L[1:])))
	print("Case #{}: {}".format(t, res))
