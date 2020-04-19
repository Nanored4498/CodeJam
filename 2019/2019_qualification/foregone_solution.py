T = int(input())
for x in range(T):
	N = input()
	first = True
	A, B = "", ""
	for d in N:
		if d == '4':
			A += '3'
			B += '1'
			first = False
		else:
			A += d
			if not first:
				B += '0'
	print("Case #{}: {} {}".format(x+1, A, B))