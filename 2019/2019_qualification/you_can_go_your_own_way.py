T = int(input())
for x in range(T):
	N = int(input())
	P = input()
	res = ""
	for c in P:
		res += 'E' if c == 'S' else 'S'
	print("Case #{}: {}".format(x+1, res))
	