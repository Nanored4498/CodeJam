T = int(input())
for t in range(1, T+1):
	X, Y, M = input().split()
	X, Y = map(int, (X, Y))
	if X == 0 and Y == 0:
		print("Case #{}: 0".format(t))
		continue
	imp = True
	for i in range(len(M)):
		c = M[i]
		if c == 'N': Y += 1
		elif c == 'S': Y -= 1
		elif c == 'E': X += 1
		else: X -= 1
		if abs(X) + abs(Y) <= i+1:
			print("Case #{}: {}".format(t, i+1))
			imp = False
			break
	if imp: print("Case #{}: IMPOSSIBLE".format(t))
